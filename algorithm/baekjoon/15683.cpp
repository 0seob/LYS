#include <bits/stdc++.h>
#include <map>
#include <list>
#include <tuple>
#include <typeinfo>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
#define X first
#define Y second
typedef long long ll;

using namespace std;

int board[10][10];
int copied[10][10];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M, in, x, y, dir, ndir, nx, ny, cnt, ans = quot, di, n_cnt, num;

vector<pair<int, int> > cctv;
vector<vector<int> > v;
vector<int> temp;

void dfs(int N, int M){
  if(M == 0){
    v.push_back(temp);
    return;
  }
  for(int i = 0; i < N; i++){
    temp.push_back(i);
    dfs(N, M-1);
    temp.pop_back();
  }
}

int main(int argc, char const *argv[]) {
  FASTIO();
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> in;
      if(in % 6){
        cctv.push_back(make_pair(i, j));
        n_cnt++;
      }
      board[i][j] = in;
    }
  }
  dfs(4, n_cnt);
  for(int i = 0; i < v.size(); i++){ //카메라 방향
    memcpy(copied, board, sizeof(board));
    cnt = 0;
    for(int j = 0; j < cctv.size(); j++){ //카메라 번호
      x = cctv[j].X;
      y = cctv[j].Y;
      num = copied[x][y]; //카메라 번호
      dir = v[i][j]; //카메라 방향
      nx = x + dx[dir];
      ny = y + dy[dir];
      if(!(nx < 0 || ny < 0 || nx >= N || ny >= M) && copied[nx][ny] != 6){
        if(copied[nx][ny] == 0) copied[nx][ny] = -1;
        while(1){
          nx += dx[dir];
          ny += dy[dir];
          if(nx < 0 || ny < 0 || nx >= N || ny >= M) break;
          if(copied[nx][ny] == 6) break;
          if(copied[nx][ny] == 0) copied[nx][ny] = -1;
        }
      }
      if(num == 2 || num == 4 || num == 5){
        ndir = (dir + 2) % 4;
        nx = x + dx[ndir];
        ny = y + dy[ndir];
        if(!(nx < 0 || ny < 0 || nx >= N || ny >= M) && copied[nx][ny] != 6){
          if(copied[nx][ny] == 0) copied[nx][ny] = -1;
          while(1){
            nx += dx[ndir];
            ny += dy[ndir];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) break;
            if(copied[nx][ny] == 6) break;
            if(copied[nx][ny] == 0) copied[nx][ny] = -1;
          }
        }
      }
      if(num == 3 || num == 4 || num == 5){
        ndir = (dir + 1) % 4;
        nx = x + dx[ndir];
        ny = y + dy[ndir];
        if(!(nx < 0 || ny < 0 || nx >= N || ny >= M) && copied[nx][ny] != 6){
          if(copied[nx][ny] == 0) copied[nx][ny] = -1;
          while(1){
            nx += dx[ndir];
            ny += dy[ndir];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) break;
            if(copied[nx][ny] == 6) break;
            if(copied[nx][ny] == 0) copied[nx][ny] = -1;
          }
        }
      }
      if(num == 5){
        ndir = (dir + 3) % 4;
        nx = x + dx[ndir];
        ny = y + dy[ndir];
        if(!(nx < 0 || ny < 0 || nx >= N || ny >= M) && copied[nx][ny] != 6){
          if(copied[nx][ny] == 0) copied[nx][ny] = -1;
          while(1){
            nx += dx[ndir];
            ny += dy[ndir];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) break;
            if(copied[nx][ny] == 6) break;
            if(copied[nx][ny] == 0) copied[nx][ny] = -1;
          }
        }
      }
    }
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        // cout << copied[i][j] << " ";
        if(copied[i][j] == 0) cnt++;
      }
      // cout << "\n";
    }
    if(cnt < ans) ans = cnt;
  }
  cout << ans;
}
