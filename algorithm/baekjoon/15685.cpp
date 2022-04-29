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

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0}; //위 왼 오 아

int N, x, y, d, g, num, ans;
bool flag;

vector<vector<int> > dc(4);

int mul(int a, int n){
  int b = 1;
  for(int i = 0; i < n; i++){
    b *= a;
  }
  return b;
}

int main(int argc, char const *argv[]) {
  FASTIO();
  cin >> N;
  for(int i = 0; i < 4; i++){
    dc[i].push_back(i);
    for(int j = 0; j < 10; j++){
      for(int k = dc[i].size() - 1; k >= 0; k--){
        dc[i].push_back((dc[i][k] + 1) % 4);
      }
    }
  }
  // for(int j = 0; j < 4; j++){
  //   for(int i = 0; i < 10; i++) cout << dc[j][i];
  //   cout << '\n';
  // }
  for(int i = 0; i < N; i++){
    cin >> x >> y >> d >> g;
    board[y][x] = 1;
    num = mul(2, g);

    for(int j = 0; j < num; j++){
      if(dc[d][j] == 0) x += 1;
      else if(dc[d][j] == 1) y -= 1;
      else if(dc[d][j] == 2) x -= 1;
      else y += 1;
      board[y][x] = 1;
      // cout << y << " " << x << '\n';
    }
  }
  for(int i = 0; i < 100; i++){
    // cout << i << " ";
    for(int j = 0; j < 100; j++){
      if(board[i][j] + board[i+1][j] + board[i][j+1] + board[i+1][j+1] == 4) ans++;
      // cout << board[i][j] << " ";
    }
    // cout << '\n';
  }
  cout << ans;
}
