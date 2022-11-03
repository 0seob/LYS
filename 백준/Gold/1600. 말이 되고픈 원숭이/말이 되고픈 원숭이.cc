#include <bits/stdc++.h>
#include <list>
#include <tuple>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
#define X first
#define Y second
typedef long long ll;

using namespace std;

int board[205][205];
int vis[205][205][32];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int hx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int hy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main(int argc, char const *argv[]) {
  FASTIO();
  int K, X, Y, ans = quot;
  cin >> K;
  cin >> Y >> X;
  for(int i = 0; i < X; i++){
    for(int j = 0; j < Y; j++){
      cin >> board[i][j];
    }
  }
  queue<tuple<int, int, int> > q;
  q.push(make_tuple(0, 0, 0));
  vis[0][0][0] = 1;
  while(!q.empty()){
    tuple<int, int, int> cur = q.front(); q.pop();
    // cout << cur.X << " " << cur.Y << '\n';
    // cout << get<0>(cur) << " " << get<1>(cur) << " " << get<2>(cur) << vis[get<0>(cur)][get<1>(cur)][get<2>(cur)]<< '\n';
    if(get<2>(cur) < K){
      for(int dir = 0; dir < 8; dir++){
        int nx = get<0>(cur) + hx[dir];
        int ny = get<1>(cur) + hy[dir];
        if(nx < 0 || nx >= X || ny < 0 || ny >= Y) continue;
        if(vis[nx][ny][get<2>(cur)+1] > 0 || board[nx][ny] == 1)  continue;
        vis[nx][ny][get<2>(cur)+1] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
        q.push(make_tuple(nx, ny, get<2>(cur)+1));
      }
    }
    for(int dir = 0; dir < 4; dir++){
      int nx = get<0>(cur) + dx[dir];
      int ny = get<1>(cur) + dy[dir];
      // cout << nx << " " << ny << "\n";
      if(nx < 0 || nx >= X || ny < 0 || ny >= Y)  continue;
      if(vis[nx][ny][get<2>(cur)] > 0 || board[nx][ny] == 1)  continue;
      vis[nx][ny][get<2>(cur)] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
      q.push(make_tuple(nx, ny, get<2>(cur)));
      // cout << nx << " " << ny << "\n";
    }
  }
  // for(int i = 0; i < H; i++){
  //   for(int j = 0; j < W; j++){
  //     cout << vis[i][j][0];
  //   }
  //   cout << '\n';
  // }
  // for(int i = 0; i < H; i++){
  //   for(int j = 0; j < W; j++){
  //     cout << vis[i][j][1];
  //   }
  //   cout << '\n';
  // }
  for(int i = 0; i < K+1; i++){
    // cout << vis[H-1][W-1][i] << " ";
    // for(int j = 0; j < X; j++){
    //   for(int k = 0; k < Y; k++){
    //     cout << vis[j][k][i];
    //   }
    //   cout << "\n";
    // }
    if(vis[X-1][Y-1][i]) ans = min(ans, vis[X-1][Y-1][i]);
  }
  if(ans != quot) cout << ans - 1;
  else cout << -1;
}
