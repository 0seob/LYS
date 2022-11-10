#include <cstdio>
#include <queue>

using namespace std;

int N,M;
int mat[101][101];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int bfs(int sy, int sx){
  queue<pair<int, int> > q;
  q.push(make_pair(sy,sx));
  mat[sy][sx]=2;
  while(!q.empty()){
    int y = q.front().first, x = q.front().second;
    q.pop();
    for(int i=0;i<4;i++){
      int yy = y + dir[i][0], xx = x + dir[i][1];
      if(yy<0 || yy>=N || xx<0 || xx>=M) continue;
      if(mat[yy][xx]==1){
        mat[yy][xx]=mat[y][x]+1;
        q.push(make_pair(yy,xx));
      }
    }
  }
  return mat[N-1][M-1]-1;
}

int main(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      scanf("%1d",&mat[i][j]);
    }
  }
  printf("%d\n",bfs(0,0));
}
