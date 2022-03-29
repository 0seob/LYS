#include <bits/stdc++.h>
#include <list>
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
  int r, c, m = 0;
  string s;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  queue<pair<int, int> > q;
  cin >> r >> c;
  for(int i = 0; i < r; i++){
    cin >> s;
    for(int j = 0; j < c; j++){
      board[i][j] = s[j];
      if(s[j] == 'F'){
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
      if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if(board[nx][ny] == '#' || vis[nx][ny] > 0) continue;
      vis[nx][ny] = vis[cur.X][cur.Y] + 1;
      q.push(make_pair(nx, ny));
    }
  }
  // for(int i = 0; i < r; i++){
  //   for(int j = 0; j < c; j++){
  //     cout << vis[i][j] << " ";
  //   }
  //   cout << '\n';
  // }cout << '\n';
  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
      if(board[i][j] == 'J'){
        q.push(make_pair(i, j));
        vis[i][j] = 1;
      }
  while(!q.empty()){
    pair<int, int> cur = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= r || ny < 0 || ny >= c){
        cout << vis[cur.X][cur.Y];
        return 0;
      }
      if(board[nx][ny] == '#' || board[nx][ny] == 'F' || (0 < vis[nx][ny] && vis[nx][ny] <= vis[cur.X][cur.Y]+1)) continue;
      vis[nx][ny] = vis[cur.X][cur.Y] + 1;
      q.push(make_pair(nx, ny));
    }
  }
  // for(int i = 0; i < r; i++){
  //   for(int j = 0; j < c; j++){
  //     cout << vis[i][j] << " ";
  //   }
  //   cout << '\n';
  // }
  cout << "IMPOSSIBLE";
}
