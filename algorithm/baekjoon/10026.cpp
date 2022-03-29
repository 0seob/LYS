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
int vis2[1005][1005];

int main(int argc, char const *argv[]) {
  FASTIO();
  int N, cnt = 0, cnt2 = 0;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  string s;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> s;
    for(int j = 0; j < N; j++)
      board[i][j] = s[j];
  }
  queue<pair<int, int> > q;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(vis[i][j] == 0){
        q.push(make_pair(i, j));
        cnt++;
      }
      while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
          if(board[nx][ny] != board[cur.X][cur.Y] || vis[nx][ny] != 0) continue;
          vis[nx][ny] = 1;
          q.push(make_pair(nx, ny));
        }
      }
    }
  }
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      if(board[i][j] == 'G') board[i][j] = 'R';
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(vis2[i][j] == 0){
        q.push(make_pair(i, j));
        cnt2++;
      }
      while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
          if(board[nx][ny] != board[cur.X][cur.Y] || vis2[nx][ny] != 0) continue;
          vis2[nx][ny] = 1;
          q.push(make_pair(nx, ny));
        }
      }
    }
  }
  cout << cnt << " " << cnt2;
}
