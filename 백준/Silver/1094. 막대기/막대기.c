#include <stdio.h>

int main() {
  int X,i;
  int min = 64;
  int sum = 0,cnt = 0;
  scanf("%d",&X);
  if(X==64){
     sum += X;
     cnt += 1;
  }
  for(i=0;X>sum;i++){
     min /= 2;
     if(X >= sum + min){
        sum += min;
        cnt += 1;
     }
   }
   printf("%d\n",cnt);
   return 0;
}
