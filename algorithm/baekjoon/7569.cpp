#include <bits/stdc++.h>
#include <list>
#include <tuple>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
#define X first
#define Y second
typedef long long ll;

using namespace std;

int board[101][101][101];
int vis[101][101][101];

int main(int argc, char const *argv[]) {
  FASTIO();
  int M, N, H, m = 0;
  int dx[6] = {1, 0, 0, -1, 0, 0};
  int dy[6] = {0, 1, 0, 0, -1, 0};
  int dz[6] = {0, 0, 1, 0, 0, -1};
  cin >> M >> N >> H;
  queue<tuple<int, int, int> > q;
  for(int k = 0; k < H; k++)
    for(int i = 0; i < N; i++)
      for(int j = 0; j < M; j++)
        cin >> board[i][j][k];
  for(int k = 0; k < H; k++){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        if(board[i][j][k] == 1 && vis[i][j][k] == 0){
          vis[i][j][k] = 1;
          q.push(make_tuple(i, j, k));
        }
        while(!q.empty()){
          tuple<int, int, int> cur = q.front(); q.pop();
          for(int dir = 0; dir < 6; dir++){
            int nx = get<0>(cur) + dx[dir];
            int ny = get<1>(cur) + dy[dir];
            int nz = get<2>(cur) + dz[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) continue;
            if(board[nx][ny][nz] != 0 || (0 < vis[nx][ny][nz] && vis[nx][ny][nz] <= vis[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1)) continue;
            vis[nx][ny][nz] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            q.push(make_tuple(nx, ny, nz));
          }
        }
      }
    }
  }
  for(int k = 0; k < H; k++){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        // cout << vis[i][j][k] << " ";
        if(board[i][j][k] != -1 && vis[i][j][k] == 0){
          cout << -1;
          return 0;
        }
        m = max(vis[i][j][k], m);
      }
      // cout << '\n';
    }
    // cout << '\n';
  }
  cout << m-1;
}
