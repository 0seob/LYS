#include <bits/stdc++.h>
#include <list>
#include <tuple>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
#define X first
#define Y second
typedef long long ll;

using namespace std;

char board[1005][1005];
int vis[1005][1005];

int main(int argc, char const *argv[]) {
  FASTIO();
  int t;
  cin >> t;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  while(t--){
    memset(board, '\0', sizeof(board));
    memset(vis, 0, sizeof(vis));
    int w, h, nx, ny, x, y, cnt = 0;
    string s;
    cin >> w >> h;
    queue<pair<int, int> > q;
    for(int i = 0; i < h; i++){
      cin >> s;
      for(int j = 0; j < w; j++){
        board[i][j] = s[j];
        if(s[j] == '*'){
          q.push(make_pair(i, j));
          vis[i][j] = 1;
        }
        else if(s[j] == '@') {
          x = i; y = j;
        }
      }
    }
    while(!q.empty()){
      pair<int, int> cur = q.front(); q.pop();
      for(int dir = 0; dir < 4; dir++){
        nx = cur.X + dx[dir];
        ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if(board[nx][ny] == '#' || vis[nx][ny] != 0) continue;
        vis[nx][ny] = vis[cur.X][cur.Y] + 1;
        q.push(make_pair(nx, ny));
      }
    }
    // for(int i = 0; i < h; i++){
    //   for(int j = 0; j < w; j++){
    //     cout << vis[i][j];
    //   }
    //   cout << '\n';
    // }
    q.push(make_pair(x, y));
    vis[x][y] = 1;
    while(!q.empty()){
      pair<int, int> cur = q.front(); q.pop();
      // cout << cur.X << " " << cur.Y << '\n';
      for(int dir = 0; dir < 4; dir++){
        nx = cur.X + dx[dir];
        ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= h || ny < 0 || ny >= w){
          cout << vis[cur.X][cur.Y] << "\n";
          cnt = 1;
          break;
        }
        if(board[nx][ny] == '#' || (vis[nx][ny] > 0 && vis[nx][ny] <= vis[cur.X][cur.Y]+1)) continue;
        vis[nx][ny] = vis[cur.X][cur.Y] + 1;
        q.push(make_pair(nx, ny));
      }
      if(nx < 0 || nx >= h || ny < 0 || ny >= w) break;
    }
    if(cnt == 0) cout << "IMPOSSIBLE\n";
    // for(int i = 0; i < h; i++){
    //   for(int j = 0; j < w; j++){
    //     cout << vis[i][j];
    //   }
    //   cout << '\n';
    // }
  }
}
