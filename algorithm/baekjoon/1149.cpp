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

int board[1005][3];
int value[1005][3];

int dx[5] = {0, -1, 1, 0 ,0}; //위 아 오 왼
int dy[5] = {0, 0, 0, 1, -1};

int N;
bool flag;

deque<deque<deque<tuple<int, int, int> > > > shark(105, deque<deque<tuple<int, int, int> > >(105));
deque<tuple<int, int, int, int, int> > state;

int main(int argc, char const *argv[]) {
  FASTIO();
  cin >> N;
  for(int i = 1; i <= N; i++){
    cin >> value[i][0] >> value[i][1] >> value[i][2];
  }
  board[1][0] = value[1][0];
  board[1][1] = value[1][1];
  board[1][2] = value[1][2];
  for(int i = 2; i <= N; i++){
    board[i][0] = min(board[i-1][1], board[i-1][2]) + value[i][0];
    board[i][1] = min(board[i-1][0], board[i-1][2]) + value[i][1];
    board[i][2] = min(board[i-1][0], board[i-1][1]) + value[i][2];
  }
  cout << min(board[N][0], min(board[N][1], board[N][2]));
}
