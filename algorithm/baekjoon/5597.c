#include <stdio.h>

int main(int argc, char const *argv[]) {
  int n, arr[31] = {};
  for(int i = 0; i < 28; i++){
    scanf("%d", &n);
    arr[n] = 1;
  }
  for(int i = 1; i < 31; i++){
    if(arr[i] == 0) printf("%d\n", i);
  }
}
