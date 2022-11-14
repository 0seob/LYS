#include <stdio.h>

int main(int argc, char const *argv[]) {
  int N,A,B,C,ret=0,ans=0;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d %d %d",&A,&B,&C);
    if(A == B){
      if(B == C){
        if(10000 + A*1000 > ret) ret = 10000 + A*1000;
      }
      else{
        if(1000 + A*100 > ret) ret = 1000 + A*100;
      }
    }
    else if(A == C){
      if(1000 + A*100 >ret) ret = 1000 + A*100;
    }
    else{
      if(B == C){
        if(1000 + B*100 > ret) ret = 1000 + B*100;
      }
      else{
        int max = (A>=B ? A:B);
        max = (max>=C ? max:C);
        if(max*100 > ret) ret = max*100;
      }
    }
    if(ret >= ans) ans = ret;
  }
  printf("%d\n", ans);
  return 0;
}
