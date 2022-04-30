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

int board[105][105];
int vis[105][105];
int vcpy[105][105];

int dx[4] = {1, 0, -1 ,0};
int dy[4] = {0, 1, 0, -1};

int N, K, in, num, ans = 1, big = 0, mv = quot, small = quot, temp, di;
bool flag;

void rotate(int k, int row, int size){ //어항 회전
  for(int i = k; i < k+size; i++){
    for(int j = 0; j < row; j++){
      board[99 + i - size*row][k + size + j] = board[99 - j][i];
      board[99 - j][i] = 0;
    }
  }
}

void rotate2(int k, int row, int size){
  for(int j = 0; j < row; j++){
    for(int i = 0; i < size; i++){
      board[100 - 2*row + j][N-1-i] = board[99 - j][k+i];
      board[99 - j][k+i] = 0;
    }
  }
}

int clean(int m){ //리턴: 물고기가 가장 많은 어항과 적은 어항의 차이
  for(int i = 0; i < N; i++)
    if(board[99][i] == m) board[99][i]++;
  int size = 1, j = 0, k = 0, row = 1;
  while(row <= N - k - size){
    rotate(k, row, size);
    k += size;
    if(j % 2 == 0) size = j/2+1;
    else size = (j+1)/2+1;
    j++;
    row = size;
    if(j % 2 == 1) row++;
  }
  memset(vis, 0, sizeof(vis));
  for(int i = 99; i > 99 - row; i--){
    for(int j = k; j < k + size; j++){
      // cout << i << " " << j << '\n';
      for(int dir = 0; dir < 4; dir++){
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if(nx <= 99 - row || ny < k || nx >= 100 || ny >= k + size) {
          if(!(nx == 99 && ny == k+size && board[nx][ny] != 0)) continue;
        }
        // cout << "nx, ny " << nx << " " << ny << '\n';
        if(board[nx][ny] - board[i][j] >= 5){
          di = (board[nx][ny] - board[i][j]) / 5;
          vis[i][j] += di;
        }
        else if(board[i][j] - board[nx][ny] >= 5){
          di = (board[i][j] - board[nx][ny]) / 5;
          vis[i][j] -= di;
        }
      }
      // cout << vis[i][j] << '\n';
    }
  }
  if(board[99][k+size]){
    for(int i = k + size; i < N; i++){
      // cout << i << " ";
      for(int dir = 0; dir < 4; dir+=2){
        int nx = i + dx[dir];
        if(nx < k + size - 1 || nx >= N) continue;
        if(board[99][nx] - board[99][i] >= 5){
          di = (board[99][nx] - board[99][i]) / 5;
          vis[99][i] += di;
        }
        else if(board[99][i] - board[99][nx] >= 5){
          di = (board[99][i] - board[99][nx]) / 5;
          vis[99][i] -= di;
        }
      }
      // cout << vis[99][i] << '\n';
    }
  }
  for(int i = 99; i > 99 - row; i--)
    for(int j = k; j < k + size; j++)
      board[i][j] += vis[i][j];
  if(board[99][k+size]){
    for(int i = k + size; i < N; i++) board[99][i] += vis[99][i];
  }
  temp = 0;
  for(int i = k; i < k + size; i++){
    for(int j = 99; j > 99 - row; j--){
      board[99][temp] = board[j][i];
      board[j][i] = 0;
      temp++;
    }
  }
  size = N/2, k = 0, row = 1;
  for(int i = 0; i < 2; i++){
    rotate2(k, row, size);
    k += size;
    if(size >= 2) size /= 2;
    row *= 2;
  }
  // cout << k << " " << size << " " << row << '\n';
  memset(vis, 0, sizeof(vis));
  size *= 2;
  for(int i = 99; i > 99 - row; i--){
    for(int j = k; j < k + size; j++){
      // cout << i << " " << j << '\n';
      for(int dir = 0; dir < 4; dir++){
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if(nx < 100 - row || ny < k || nx >= 100 || ny >= N) continue;
        // cout << "nx, ny " << nx << " " << ny << '\n';
        if(board[nx][ny] - board[i][j] >= 5){
          di = (board[nx][ny] - board[i][j]) / 5;
          vis[i][j] += di;
        }
        else if(board[i][j] - board[nx][ny] >= 5){
          di = (board[i][j] - board[nx][ny]) / 5;
          vis[i][j] -= di;
        }
      }
      // cout << vis[i][j] << '\n';
    }
  }

  for(int i = 99; i > 99 - row; i--)
    for(int j = k; j < k + size; j++)
      board[i][j] += vis[i][j];
  // for(int p = 96; p <= 99; p++){
  //   for(int q = 0; q < N; q++){
  //     cout << board[p][q] << " ";
  //   }
  //   cout << '\n';
  // }
  temp = 0;
  for(int i = k; i < k + size; i++){
    for(int j = 99; j > 99 - row; j--){
      board[99][temp] = board[j][i];
      board[j][i] = 0;
      temp++;
    }
  }
  // cout << board[99][0] << " " << board[99][1] << " " <<  board[99][2] << " " <<  board[99][3] << '\n';
  big = 0, small = quot;
  for(int i = 0; i < N; i++){
    if(board[99][i] >= big) big = board[99][i];
    if(board[99][i] <= small) small = board[99][i];
  }
  mv = small;
  return big - small;
}

int main(int argc, char const *argv[]) {
  FASTIO();
  cin >> N >> K;
  for(int i = 0; i < N; i++){
    cin >> in;
    board[99][i] = in;
    mv = min(in, mv);
  }
  // num = clean(mv);
  // cout << num;
  while(1){
    num = clean(mv);
    if(num <= K){
      cout << ans;
      return 0;
    }
    ans++;
  }
}
