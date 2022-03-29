#include <bits/stdc++.h>
#include <list>
#include <tuple>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
#define X first
#define Y second
typedef long long ll;

using namespace std;

char board[1000005];
int vis[1000005];

int dx[2] = {1, -1};
int dy[4] = {0, 1, 0, -1};

int main(int argc, char const *argv[]) {
  FASTIO();
  int F, S, G, U, D, dx[2];
  cin >> F >> S >> G >> U >> D;
  dx[0] = U; dx[1] = -1*D;
  queue<int> q;
  q.push(S);
  vis[S] = 1;
  if(S == G){
    cout << 0;
    return 0;
  }
  while(!q.empty()){
    int cur = q.front(); q.pop();
    for(int dir = 0; dir < 2; dir++){
      int nx = cur + dx[dir];
      if(nx <= 0 || nx > F) continue;
      if(vis[nx] > 0) continue;
      // cout << "nx = " << nx << " vis = " << vis[cur] << '\n';
      if(nx == G){
        cout << vis[cur];
        return 0;
      }
      vis[nx] = vis[cur] + 1;
      q.push(nx);
    }
  }
  cout << "use the stairs";
}
