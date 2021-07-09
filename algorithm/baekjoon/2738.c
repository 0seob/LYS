#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  int A[101][101] = {}, B[101][101] = {};
  int N, M;
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      scanf("%d", &A[i][j]);
    }
  }
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      scanf("%d", &B[i][j]);
    }
  }
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      printf("%d ", A[i][j] + B[i][j]);
    }
    printf("\n");
  }
  return 0;
}
