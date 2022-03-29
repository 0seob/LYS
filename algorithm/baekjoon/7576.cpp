#include <bits/stdc++.h>
#include <list>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
#define X first
#define Y second
typedef long long ll;

using namespace std;

int board[1005][1005];
int vis[1005][1005];

int main(int argc, char const *argv[]) {
  FASTIO();
  int m, n, max = 0, cnt = 0;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  cin >> m >> n;
  queue<pair<int, int> > q;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board[i][j];
      if(board[i][j] == 1){
        q.push(make_pair(i, j));
        vis[i][j] = 1;
      }
    }
  }
  while(!q.empty()){
    pair<int, int> cur = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(board[nx][ny] == -1 || (vis[nx][ny] != 0 && vis[nx][ny] <= vis[cur.X][cur.Y] + 1)) continue;
      vis[nx][ny] = vis[cur.X][cur.Y] + 1;
      q.push(make_pair(nx, ny));
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(vis[i][j] > max) max = vis[i][j];
      else if(board[i][j] != -1 && vis[i][j] == 0) cnt++;
    }
  }
  if(cnt != 0) cout << -1;
  else cout << max-1;
}
