#include <stdio.h>

int gcd(int a, int b){
  if(b==0)  return a;
  else  return gcd(b,a%b);
}

int main(){
  int T; scanf("%d",&T);
  int A,B;
  while(T--){
      scanf("%d %d",&A,&B);
      printf("%d\n",A*B/gcd(A,B));
  }
  return 0;
}
