#include <cstdio>
#include <algorithm>

using namespace std;

int N,M;
char arr[55][55] = {};

int func(int x, int y){
  int b=0,w=0;
  for(int i=0; i < 8; i++){
    for(int j=0; j < 8; j++){
      if((i+j)%2 == 0 && arr[x+i][y+j] == 'W') b++;
      if((i+j)%2 == 1 && arr[x+i][y+j] == 'B') b++;
      if((i+j)%2 == 0 && arr[x+i][y+j] == 'B') w++;
      if((i+j)%2 == 1 && arr[x+i][y+j] == 'W') w++;
    }
  }
  return min(b,w);
}

int main(int argc, char const *argv[]) {
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%s",arr[i]);
  }
  int ans = 100;
  for(int i=0; i < N-7; i++){
    for(int j=0; j < M-7; j++){
      ans = min(ans, func(i,j));
    }
  }
  printf("%d\n",ans);
  return 0;
}
