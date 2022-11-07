#include <bits/stdc++.h>
#include <list>
#include <tuple>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
#define X first
#define Y second
typedef long long ll;

using namespace std;

int board[105][105];
int vis[105][105];
int dist[105][105];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(int argc, char const *argv[]) {
  FASTIO();
  int N, cnt = 1, ans = 1000000;
  cin >> N;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> board[i][j];
    }
  }
  queue<pair<int, int> > q;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(board[i][j] == 1 && vis[i][j] == 0){
        q.push(make_pair(i, j));
        board[i][j] = cnt;
        vis[i][j] = 1;
        while(!q.empty()){
          pair<int, int> cur = q.front(); q.pop();
          for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(board[nx][ny] == 0 || vis[nx][ny] >= 1) continue;
            q.push(make_pair(nx, ny));
            board[nx][ny] = cnt;
            vis[nx][ny] = 1;
          }
        } cnt++;
      }
    }
  }
  for(int i = 0; i < N; i++){
    fill(dist[i], dist[i]+N, -1);
  }
  queue<pair<int, int> > q2;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(board[i][j] != 0){
        q2.push(make_pair(i, j));
        dist[i][j] = 0;
      }
    }
  }
  while(!q2.empty()){
    pair<int, int> cur = q2.front(); q2.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || ny < 0 || nx >= N || ny >= N || board[cur.X][cur.Y] == board[nx][ny]) continue;
      if(board[nx][ny] != 0){
        ans = min(ans, dist[cur.X][cur.Y] + dist[nx][ny]);
      }
      else{
        board[nx][ny] = board[cur.X][cur.Y];
        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        q2.push(make_pair(nx, ny));
      }
    }
  }
  cout << ans;
}
