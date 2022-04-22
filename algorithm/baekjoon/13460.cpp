#include <bits/stdc++.h>
#include <list>
#include <tuple>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
#define X first
#define Y second
typedef long long ll;

using namespace std;

char board[11][11][11][11][11];
int vis[11][11][11][11][11];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


int main(int argc, char const *argv[]) {
  FASTIO();
  int X, Y;
  char in;
  cin >> X >> Y;
  for(int i = 0; i < X; i++){
    for(int j = 0; j < Y; j++){
      cin >> in;
      if(in == 'R'){
        pair<int, int> red = make_pair(i, j);
        board[i][j] = '.';
      }
      else if(in == 'B'){
        pair<int, int> blue = make_pair(i, j);
        board[i][j] = '.';
      }
      else board[i][j] = in;
    }
  }

  queue<tuple<int, int, int, int, int> > q;
  q.push(make_tuple(red.X, red.Y, blue.X, blue.Y, 0));
  vis[red.X][red.Y][blue.X][blue.Y][0] = 1;
  while(!q.empty()){
    tuple<int, int, int, int, int> cur = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++){
      if(dir < 2){
        int rx = get<0>(cur) + dx[dir];
        int bx = get<2>(cur) + dx[dir];
        while(!(rx + dx[dir] == '#')){
          if(rx + dx[dir] == 'O'){

          }
          else rx = rx + dx[dir];
        while(!(bx + dx[dir] == '#')) bx = bx + dx[dir];
      }
      else{
        int ry = get<1>(cur) + dy[dir];
        int by = get<3>(cur) + dy[dir];
        while(!(ry == '.' && ry + dy[dir] == '#')) ry = ry + dy[dir];
        while(!(by == '.' && by + dy[dir] == '#')) by = by + dy[dir];
      }

    }
  }
}
