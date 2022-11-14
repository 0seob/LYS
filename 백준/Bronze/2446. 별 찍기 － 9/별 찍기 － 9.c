#include <stdio.h>

int main(){
  int N;
  scanf("%d", &N);
  for(int i = 0 ; i < 2*N-1 ; i++){
    if(i < N){
      for(int j = 0 ; j < i ; j++){
        printf(" ");
      }
      for(int k = 0 ; k < 2*(N-i)-1 ; k++){
        printf("*");
      }
      printf("\n");
    }
    else{
      for(int l = 0 ; l < 2*N-i-2 ; l++){
        printf(" ");
      }
      for(int m = 0 ; m < 2*(i-N+2)-1 ; m++){
        printf("*");
      }
      printf("\n");
    }
  }
}