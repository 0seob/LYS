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
  int M, N, K, lx, ly, rx, ry, cnt = 0;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  vector<int> v;
  cin >> M >> N >> K;
  while(K--){
    cin >> lx >> ly >> rx >> ry;
    for(int i = ly; i < ry; i++)
      for(int j = lx; j < rx; j++)
        board[i][j] = 1;
  }
  queue<pair<int, int> > q;
  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      if(board[i][j] == 0 && vis[i][j] == 0){
        q.push(make_pair(i, j));
        vis[i][j] = 1;
        cnt++;
        int size = 0;
        while(!q.empty()){
          pair<int, int> cur = q.front(); q.pop(); size++;
          for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if(board[nx][ny] == 1 || vis[nx][ny] == 1) continue;
            vis[nx][ny] = 1;
            q.push(make_pair(nx, ny));
          }
        }
        v.push_back(size);
      }
    }
  }
  cout << cnt << '\n';
  sort(v.begin(), v.end());
  for(int i = 0; i < v.size(); i++){
    cout << v[i] << " ";
  }
}
