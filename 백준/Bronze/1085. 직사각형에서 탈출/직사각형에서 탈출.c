#include <stdio.h>

int main(int argc, char const *argv[]) {
  int x,y,w,h,ans1=0,ans2=0;
  scanf("%d %d %d %d",&x,&y,&w,&h);
  if(x<w-x) ans1 = x;
  else ans1 = w-x;
  if(y<h-y) ans2 = y;
  else ans2 = h-y;
  if(ans1>ans2) printf("%d\n",ans2);
  else printf("%d\n",ans1);
  return 0;
}