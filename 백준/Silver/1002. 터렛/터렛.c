#include <stdio.h>
#include <math.h>

int max(a,b){
  if(a>b)
    return a;
  else
    return b;
}

int min(a,b){
  if(a>b)
    return b;
  else
    return a;
}

int main(){
	int T,x1,x2,y1,y2,r1,r2,ans;
  double R;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
    R = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    int big = max(r1,r2);
    int small = min(r1,r2);
    if(R == 0.0){
      if(big == small)
        ans = -1;
      else
        ans = 0;
    }
    else{
      if(big-small < R && big+small > R)
        ans = 2;
      else if(big+small == R || big-small == R)
        ans = 1;
      else
        ans = 0;
    }
  printf("%d\n",ans);
	}
}
