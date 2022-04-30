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

int pipe[20][20][3];
int board[20][20];

int dx[5] = {0, -1, 1, 0 ,0}; //위 아 오 왼
int dy[5] = {0, 0, 0, 1, -1};

int N, r, c;
bool flag;

deque<deque<deque<tuple<int, int, int> > > > shark(105, deque<deque<tuple<int, int, int> > >(105));
deque<tuple<int, int, int, int, int> > state;

int main(int argc, char const *argv[]) {
  FASTIO();
  cin >> N;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      cin >> board[i][j];
    }
  }
  pipe[1][2][0] = 1;
  for(int i = 1; i <= N; i++){
    for(int j = 3; j <= N; j++){
      if(board[i][j] != 1){
        pipe[i][j][0] = pipe[i][j-1][0] + pipe[i][j-1][2];
        pipe[i][j][1] = pipe[i-1][j][1] + pipe[i-1][j][2];
        if(board[i-1][j] == 0 && board[i][j-1] == 0) pipe[i][j][2] = pipe[i-1][j-1][0] + pipe[i-1][j-1][1] + pipe[i-1][j-1][2];
      }
    }
  }
  cout << pipe[N][N][0] + pipe[N][N][1] + pipe[N][N][2];
}
