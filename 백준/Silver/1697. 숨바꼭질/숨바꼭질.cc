#include <bits/stdc++.h>
#include <list>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
#define X first
#define Y second
typedef long long ll;

using namespace std;

int board[1005][1005];
int vis[200005];

int main(int argc, char const *argv[]) {
  FASTIO();
  int N, K, nx;
  int dx[3] = {-1, 1, 2};
  cin >> N >> K;
  queue<int> q;
  q.push(N);
  vis[N] = 1;
  while(!q.empty()){
    int cur = q.front(); q.pop();
    for(int dir = 0; dir < 3; dir++){
      if(dir == 2) nx = cur * dx[dir];
      else nx = cur + dx[dir];
      if(nx < 0 || nx >= 200005) continue;
      if(vis[nx] > 0) continue;
      vis[nx] = vis[cur] + 1;
      q.push(nx);
    }
  }
  cout <<  vis[K] - 1;
}