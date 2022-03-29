#include <bits/stdc++.h>
#include <list>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
#define X first
#define Y second
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  int T, M, N, K, X, Y;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  cin >> T;
  while(T--){
    int board[1005][1005] = {};
    int vis[1005][1005] = {};
    int cnt = 0;
    cin >> M >> N >> K;
    for(int i = 0; i < K; i++){
      cin >> X >> Y;
      board[Y][X] = 1;
    }
    queue<pair<int, int> > q;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        if(board[i][j] == 1 && vis[i][j] == 0){
          vis[i][j] = 1;
          q.push(make_pair(i, j));
          cnt++;
        }
        while(!q.empty()){
          pair<int, int> cur = q.front(); q.pop();
          for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(board[nx][ny] != 1 || vis[nx][ny] != 0) continue;
            vis[nx][ny] = 1;
            q.push(make_pair(nx, ny));
          }
        }
      }
    }
    cout << cnt << '\n';
  }
}
