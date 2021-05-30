/*
 * Copyright 2021. Heekuck Oh, all rights reserved
 * 이 프로그램은 한양대학교 ERICA 소프트웨어학부 재학생을 위한 교육용으로 제작되었습니다.
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include "threadpool.h"

/*
 * 스레드 풀의 FIFO 대기열 길이와 일꾼 스레드의 갯수를 지정한다.
 */
#define QUEUE_SIZE 10
#define NUMBER_OF_BEES 3

/*
 * 스레드를 통해 실행할 작업 함수와 함수의 인자정보 구조체 타입
 */
typedef struct {
    void (*function)(void *p);
    void *data;
} task_t;

/*
 * 스레드 풀의 FIFO 대기열인 worktodo 배열로 원형 버퍼의 역할을 한다.
 */
typedef struct {                  //큐 구조체 정의
  int front;
  int rear;
} queue;
/*
 * mutex는 대기열을 조회하거나 변경하기 위해 사용하는 상호배타 락이다.
 */
static task_t worktodo[QUEUE_SIZE];
static pthread_t bee[NUMBER_OF_BEES];
static sem_t *sem;
static pthread_mutex_t mutex;
static queue queue1;

static void initQueue(queue queue){ //큐의 요소 front, rear를 0으로 초기화
  queue.front = 0;
  queue.rear = 0;
}

static int isFull(queue queue){  //큐가 가득찼는지 확인하는 함수
  return (((queue.rear)+1)%QUEUE_SIZE) == queue.front;
}

static int isEmpty(queue queue){ //큐가 비어있는지 확인하는 함수
  return (((queue.front)+1)%QUEUE_SIZE) == queue.rear;
}

/*
 * 대기열에 새 작업을 넣는다.
 * enqueue()는 성공하면 0, 꽉 차서 넣을 수 없으면 1을 리턴한다.
 */
static int enqueue(task_t t)
{
  if (isFull(queue1)){            //큐가 가득 찼을때
    return 1;
  }
  worktodo[queue1.rear] = t;    //queue의 worktodo에 입력값 t를 넣어준다.
  queue1.rear = ((queue1.rear)+1)%QUEUE_SIZE; // rear값을 하나 늘려준다.
  return 0;
}

/*
 * 대기열에서 실행을 기다리는 작업을 꺼낸다.
 * dequeue()는 성공하면 0, 대기열에 작업이 없으면 1을 리턴한다.
 */
static int dequeue(task_t *t)
{
  if (isEmpty(queue1))//큐가 비었을 때
    {
      return 1;
    }
  queue1.front = (((queue1.front)+1)%QUEUE_SIZE); //front값을 하나 늘려준다.
  t -> function = worktodo[queue1.front].function;
  t -> data = worktodo[queue1.front].data;
  return 0;
}

/*
 * bee는 작업을 수행하는 일꾼 스레드의 ID를 저장하는 배열이다.
 * 세마포 sem은 카운팅 세마포로 그 값은 대기열에 입력된 작업의 갯수를 나타낸다.
 */

/*
 * 풀에 있는 일꾼 스레드로 FIFO 대기열에서 기다리고 있는 작업을 하나씩 꺼내서 실행한다.
 */
static void *worker(void *param)
{
  task_t *work = (task_t*)malloc(sizeof(task_t)); //task 동적할당
  while(1) {                                      //while문이 돌아가는동안
    sem_wait(sem);                                //semphore와 mutexlock으로 잠궈서 스레드의 단독실행을 보장하고
    pthread_mutex_lock(&mutex);
    if (dequeue(work)) {
      pthread_mutex_unlock(&mutex);
    }
    else {
      dequeue(work);                              //dequeue로 queue에 들어있는 함수를 task에 할당
      pthread_mutex_unlock(&mutex);
      work->function(work->data);                 //task에 들어있는 함수실행
    }
  }
  pthread_exit(0);
}

/*
 * 스레드 풀에서 실행시킬 함수와 인자의 주소를 넘겨주며 작업을 요청한다.
 * pool_submit()은 작업 요청이 성공하면 0을, 그렇지 않으면 1을 리턴한다.
 */
int pool_submit(void (*f)(void *p), void *p)
{
  pthread_mutex_lock(&mutex);                     //mutexlock을 걸고
  task_t *work = (task_t*)malloc(sizeof(task_t));                           //입력받은 task를위해 동적할당
  work->function = f;
  work->data = p;
  sem_post(sem);
  int ret = enqueue(*work);                       //입력받은 함수와 인자를 queue에 넣은 후
  pthread_mutex_unlock(&mutex);                   //mutexlock을 해제한다.
  return ret;
}

/*
 * 각종 변수, 락, 세마포, 일꾼 스레드 생성 등 스레드 풀을 초기화한다.
 */
void pool_init(void)
{
  pthread_mutex_init(&mutex,0);                     //mutexlock 초기화
  initQueue(queue1);                                //queue 초기화
  sem = sem_open("sem",O_CREAT,0644,0);             //semaphore 초기화
  for(int i = 0; i < NUMBER_OF_BEES; i++){
    pthread_create(&bee[i], NULL, worker, NULL);    //thread 생성
  }
}

/*
 * 현재 진행 중인 모든 일꾼 스레드를 종료시키고, 락과 세마포를 제거한다.
 */
void pool_shutdown(void)
{
  for(int i = 0; i < NUMBER_OF_BEES; i++){
    pthread_cancel(bee[i]);                         //thread를 철회하고 종료시킨다.
  }
  pthread_mutex_destroy(&mutex);                    //사용한 mutexlock과 semaphore를 삭제한다.
  sem_close(sem); sem_unlink("sem");
  for(int i = 0; i < NUMBER_OF_BEES; i++){
    pthread_join(bee[i],NULL);                         //thread를 철회하고 종료시킨다.
  }
}
