#include <stdio.h>

int main(){
  int N,M,arr[301][301];
  scanf("%d %d",&N,&M);
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      scanf("%d",&arr[i][j]);
    }
  }
  int K;
  scanf("%d",&K);
  for(int i=0;i<K;i++){
    int y1,x1,y2,x2;
    scanf("%d %d %d %d",&y1,&x1,&y2,&x2);
    int sum = 0;
    for(int p=y1;p<=y2;p++){
      for(int q=x1;q<=x2;q++){
        sum += arr[p][q];
      }
    }
    printf("%d\n",sum); 
  }
}
