#include <bits/stdc++.h>
#include <list>
#include <tuple>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
#define X first
#define Y second
typedef long long ll;

using namespace std;

int board[100005];
int vis[100005];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void run(int x){
  int cur = x;
  while(1){
    vis[cur] = x;
    cur = board[cur];
    if(vis[cur] == x){
      while(vis[cur] != -1){
        vis[cur] = -1;
        cur = board[cur];
      }
      return;
    }
    else if(vis[cur] != 0) return;
  }
}

int main(int argc, char const *argv[]) {
    FASTIO();
    int T;
    cin >> T;
    while(T--){
      int n, cnt = 0;
      cin >> n;
      fill(vis+1, vis+n+1, 0);
      for(int i = 1; i <= n; i++){
        cin >> board[i];
      }
      for(int i = 1; i <= n; i++){
        if(vis[i] == 0) run(i);
      }
      for(int i = 1; i <= n; i++){
        if(vis[i] != -1) cnt++;
      }
      cout << cnt << '\n';
    }
}
