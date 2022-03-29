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

int main(int argc, char const *argv[]) {
  FASTIO();
  int t;
  cin >> t;
  int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
  int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
  while(t--){
    int vis[305][305] = {};
    int l, x, y, cnt = 0;
    cin >> l;
    queue<pair<int, int> > q;
    cin >> x >> y;
    q.push(make_pair(x, y));
    vis[x][y] = 1;
    cin >> x >> y;
    while(!q.empty()){
      pair<int, int> cur = q.front(); q.pop();
      if(cur.X == x && cur.Y == y){
        cout << vis[cur.X][cur.Y]-1 << '\n';
        break;
      }
      for(int dir = 0; dir < 8; dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
        if(vis[nx][ny] >= 1) continue;
        vis[nx][ny] = vis[cur.X][cur.Y] + 1;
        q.push(make_pair(nx, ny));
      }
    }
  }
}
