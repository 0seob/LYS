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

typedef struct dice_struct{
  int top, bottom, left, right, front, back;
}DS; DS t;

int N, M, K, x, y, d, g, num, ans;
bool flag;

void dice(int x, int y, int num){
  int temp;
  if(num == 1){
    temp = t.top;
    t.top = t.left;
    t.left = t.bottom;
    t.bottom = t.right;
    t.right = temp;
  }
  else if(num == 2){
    temp = t.top;
    t.top = t.right;
    t.right = t.bottom;
    t.bottom = t.left;
    t.left = temp;
  }
  else if(num == 3){
    temp = t.top;
    t.top = t.front;
    t.front = t.bottom;
    t.bottom = t.back;
    t.back = temp;
  }
  else{
    temp = t.top;
    t.top = t.back;
    t.back = t.bottom;
    t.bottom = t.front;
    t.front = temp;
  }
  if(board[x][y] == 0) board[x][y] = t.bottom;
  else {
    t.bottom = board[x][y];
    board[x][y] = 0;
  }
  cout << t.top << '\n';
}

int main(int argc, char const *argv[]) {
  FASTIO();
  cin >> N >> M >> x >> y >> K;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      cin >> board[i][j];
  for(int i = 0; i < K; i++){
    cin >> num;
    if(num == 1 && y+1 < M){
      y += 1;
      dice(x, y, num);
    }
    else if(num == 2 && y-1 >= 0){
      y -= 1;
      dice(x, y, num);
    }
    else if(num == 3 && x-1 >= 0){
      x -= 1;
      dice(x, y, num);
    }
    else if(num == 4 && x+1 < N){
      x += 1;
      dice(x, y, num);
    }
  }
}
