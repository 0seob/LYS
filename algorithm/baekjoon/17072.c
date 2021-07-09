#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  int N, M, Arr[401][401], R, G, B, I;
  int ASCII;
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      scanf("%d %d %d", &R, &G, &B);
      I = 2126*R + 7152*G + 722*B;
      if(0 <= I && I < 510000) {
        ASCII = 35;
        Arr[i][j] = ASCII;
      }
      else if(510000 <= I && I < 1020000){
        ASCII = 111;
        Arr[i][j] = ASCII;
      }
      else if(1020000 <= I && I < 1530000){
        ASCII = 43;
        Arr[i][j] = ASCII;
      }
      else if(1530000 <= I && I < 2040000){
        ASCII = 45;
        Arr[i][j] = ASCII;
      }
      else if(2040000 <= I){
        ASCII = 46;
        Arr[i][j] = ASCII;
      }
    }
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      printf("%c", Arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}
