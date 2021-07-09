#include <stdio.h>

int main(int argc, char const *argv[]) {
  int N, var, arr[10001] = {};
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%d", &var);
    arr[var]++;
  }
  for(int i = 1; i < 10001; i++){
    while(arr[i] > 0){
      printf("%d\n", i);
      arr[i]--;
    }
  }
}
