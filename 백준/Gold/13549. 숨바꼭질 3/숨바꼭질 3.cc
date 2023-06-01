#include <bits/stdc++.h>
#include <list>
#include <tuple>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
#define X first
#define Y second
typedef long long ll;

using namespace std;

int board[200005];
int vis[200005];

int dx[2] = {1, -1};
int dy[4] = {0, 1, 0, -1};

int main(int argc, char const *argv[]) {
  FASTIO();
  int N, K;
  cin >> N >> K;
  if(N >= K){
    cout << N-K;
    return 0;
  }
  queue<int> q;
  q.push(N);
  vis[N] = 1;
  int temp = N;
  while(temp <= K){
    temp *= 2;
    if(vis[temp] > 0) break;
    vis[temp] = vis[N];
    if(temp == K){
      cout << vis[temp] - 1;
      return 0;
    }
    q.push(temp);
  }
  while(!q.empty()){
    int cur = q.front(); q.pop();
    for(int dir = 0; dir < 2; dir++){
      int nx = cur + dx[dir];
      if(nx < 0 || nx >= 100001) continue;
      if(vis[nx] > 0) continue;
      vis[nx] = vis[cur] + 1;
      if(nx == K){
        cout << vis[nx] - 1;
        return 0;
      }
      q.push(nx);
      int temp = nx;
      while(temp <= K){
        temp *= 2;
        if(vis[temp] > 0) break;
        vis[temp] = vis[nx];
        if(temp == K){
          cout << vis[temp] - 1;
          return 0;
        }
        q.push(temp);
      }
    }
  }
}
