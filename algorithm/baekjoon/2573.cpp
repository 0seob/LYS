#include <bits/stdc++.h>
#include <list>
#include <tuple>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
#define X first
#define Y second
typedef long long ll;

using namespace std;

int board[305][305];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(int argc, char const *argv[]) {
  FASTIO();
  int N, M, year = 1, bd = 0, in;
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> in;
      if(in != 0){
        board[i][j] = in;
        bd++;
      }
    }
  }
  // cout << bd << '\n';
  while(bd > 0){
    int melt[305][305] = {};
    int vis[305][305] = {};
    int cnt = 0, land = 0;
    bd = 0;
    for(int i = 1; i < N-1; i++){ //count sea around ice
      for(int j = 1; j < M-1; j++){
        if(board[i][j] != 0){
          bd++;
          for(int dir = 0; dir < 4; dir++){
            int nx = i + dx[dir];
            int ny = j + dy[dir];
            if(board[nx][ny] == 0) melt[i][j]++;
          }
        }
      }
    }
    if(bd == 0){
      cout << "0\n";
      return 0;
    }
    for(int i = 1; i < N-1; i++){ //ice melt
      for(int j = 1; j < M-1; j++){
        board[i][j] - melt[i][j] > 0 ? board[i][j] -= melt[i][j] : board[i][j] = 0;
        // cout << board[i][j];
      }
      // cout << "\n";
    }

    queue<pair<int, int> > q;
    for(int i = 1; i < N-1; i++){ //bfs
      for(int j = 1; j < M-1; j++){
        if(board[i][j] != 0 && vis[i][j] == 0){
          q.push(make_pair(i, j));
          vis[i][j] = 1;
          cnt++;
          if(cnt == 2){
            cout << year;
            return 0;
          }
          while(!q.empty()){
            pair<int, int> cur = q.front(); q.pop();
            for(int dir = 0; dir < 4; dir++){
              int nx = cur.X + dx[dir];
              int ny = cur.Y + dy[dir];
              if(vis[nx][ny] > 0 || board[nx][ny] == 0) continue;
              q.push(make_pair(nx, ny));
              vis[nx][ny] = 1;
            }
          }
        }
      }
    }
    year++;
  }
}
