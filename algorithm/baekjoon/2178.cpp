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
  int n, m;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  string s;
  queue<pair<int, int> >q;
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> s;
    for(int j = 1; j <= m; j++){
      board[i][j] = (int)(s[j-1] - '0');
    }
  }
  vis[1][1] = 1;
  q.push(make_pair(1, 1));
  while(!q.empty()){
    pair<int, int> cur = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 1 || nx >= n+1 || ny < 1 || ny >= m+1) continue;
      if(board[nx][ny] == 0 || vis[nx][ny] != 0) continue;
      vis[nx][ny] = vis[cur.X][cur.Y] + 1;
      q.push(make_pair(nx, ny));
    }
  }
  cout << vis[n][m];
}
