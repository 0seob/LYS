#include <stdio.h>

int main(){
  int N,sum=0,M=0;
  float ans=0,arr[1000]={};
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%f",&arr[i]);
    if(M<arr[i]){
      M = arr[i];
    }
  }
  for(int j=0;j<N;j++){
    arr[j] = arr[j]/M*100;
    ans += arr[j];
  }
  ans = ans/N;

  printf("%.2f",ans);
}