#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define MAX_LINE 80

int main(int argc, char const *argv[]) {
  char *args[MAX_LINE/2 + 1];                       //배열 선언
  int should_run = 1;                               //should_run 선언
  int mypipe[2];                                    //파이프 선언
  int status;                                       //process status
  int switch_run = 0;                               //should_run 상태

  while(should_run){
    memset(args,'\0',sizeof(args));                 //포인터 배열 초기화
    printf("osh>");
    fflush(stdout);
    char input[MAX_LINE];                           //임시 저장공간 선언
    fgets(input, MAX_LINE, stdin);                  //문자열 입력
    input[strlen(input) - 1] = '\0';                //개행문자를 0으로 초기화

    char *ptr = strtok(input, " ");                 //입력받은 문자열 파싱
    int ptrnum = 0;
    while(ptr != NULL){
      args[ptrnum] = ptr;
      ptrnum++;
      if(strcmp(ptr,"exit") == 0) switch_run = 1;   //exit를 만나면 switch_run의 상태가 바뀜
      ptr = strtok(NULL, " ");
    }

    if(switch_run == 1) should_run = 0;

    int i = 0, j = 0;                                   //while문 진행동안 진행위치 확인을 위한 변수
    int is_ampersand = 0;                           //& 존재를 확인하기위한 변수

    while(args[j] != NULL){                         //입력받은 문자열에서 &를 발견하면 is_ampersand의 상태가 바뀜
      if(strcmp(args[j], "&") == 0){
        is_ampersand = 1;
        args[j] = NULL;
      }
      j++;
    }
    pid_t pid1, pid2;                               //fork()를 위한 pid선언
    pid1 = fork();

    while(args[i] != NULL)
    {

      if(pid1 < 0)                                  //오류
      {
        fprintf(stderr, "Fork Failed\n");
        return 1;
      }

      else if(pid1 == 0){                           //자식 프로세스

        if(is_ampersand == 1)                       //& 유무 확인
        {
          signal(SIGINT, SIG_IGN);                  //존재하면 신호무시
          printf("getpid : %d\n", getpid());
        }
        else
        {
          signal(SIGINT, SIG_DFL);                  //존재하지않으면 신호받음
        }

        if(strcmp(args[i], "<") == 0)               // < redirection
        {
          int fd = open(args[i+1], O_RDONLY);
          dup2(fd, STDIN_FILENO);
          close(fd);
          args[i] = NULL;
          execvp(args[0], args);
        }

        else if(strcmp(args[i], ">") == 0)          // > redirection
        {
          int fd = open(args[i+1], O_WRONLY | O_CREAT, 0666);
          dup2(fd, STDOUT_FILENO);
          close(fd);
          args[i] = NULL;
          execvp(args[0], args);
        }


        else if(strcmp(args[i], "|") == 0)          // | 파이프 설정
        {
          args[i] = NULL;
          pipe(mypipe);
          pid2 = fork();

          if(pid2 < 0)                              //오류
          {
            fprintf(stderr, "Fork Failed\n");
            return 1;
          }

          else if(pid2 == 0)                        //출력 프로세스
          {
            dup2(mypipe[1], STDOUT_FILENO);
            close(mypipe[0]);
            execvp(args[0], args);
          }

          else                                      //입력 프로세스
          {
            dup2(mypipe[0], STDIN_FILENO);
            close(mypipe[1]);
            execvp(args[i+1], &args[i+1]);
          }
        }


        else                                        //어떠한 redircetion도 없을 경우
        {
          if(args[i+1] == NULL) execvp(args[0], args);
        }
      }

      else                                          //부모 프로세스
      {
        if(is_ampersand == 1)                       //자식 프로세스가 백그라운드로 수행중이라면
        {                                           //부모 프로세스는 자식을 기다리지 않음
          waitpid(pid1, &status, WNOHANG);
        }
        else
        {
          waitpid(pid1, &status, 0);               //자식 프로세스가 백그라운드에서 실행중이 아니라면
        }                                           //부모 프로세스는 자식 프로세스를 기다렸다가 실행
      }
      i++;
    }
  }
  return 0;
}
