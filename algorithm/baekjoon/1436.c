#include <stdio.h>

int main(int argc, char const *argv[]) {
  int N, i = 1, cnt = 0, ans;
  scanf("%d",&N);
  while(cnt != N){
    int temp = 0;
    int item = i;
    while(item > 0){
      if(item%10 == 6){
        temp++;
      }
      else{
        temp = 0;
      }
      item /= 10;
      if(temp == 3){
        cnt++;
        break;
      }
    }
    if(cnt == N){
      ans = i;
    }
    i++;
  }
  printf("%d\n",ans);
  return 0;
}
