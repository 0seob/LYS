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

int board[21][21];
int vis[21][21];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0}; //위 왼 오 아

int N, big = 2, in, ti, fish_num, tp;
bool flag;

vector<pair<int, int> > cctv;
vector<vector<int> > v;
vector<int> temp;
pair<int, int> ss;

int main(int argc, char const *argv[]) {
  FASTIO();
  cin >> N;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> in;
      board[i][j] = in;
      if(in == 9){
        ss = {i, j};
        board[i][j] = 0;
      }
      else if(in % 7) fish_num++;
    }
  }
  for(int i = 0; i < fish_num; i++){
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int> > q;
    flag = false;
    q.push(ss);
    vis[ss.X][ss.Y] = 1;
    int tmp = quot, temp = 0;
    vector<tuple<int, int, int> > t;
    while(!q.empty()){
      pair<int, int> cur = q.front(); q.pop();
      for(int dir = 0; dir < 4; dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if(board[nx][ny] > big || vis[nx][ny] != 0) continue;
        vis[nx][ny] = vis[cur.X][cur.Y] + 1;
        // cout << nx << " " << ny << '\n';
        if(0 < board[nx][ny] && board[nx][ny] < big){
          t.push_back(make_tuple(vis[nx][ny], nx, ny));
          flag = true;
          if(temp == 0){
            temp = 1;
            tmp = vis[nx][ny];
          }
        }
        if(vis[nx][ny] <= tmp) q.push(make_pair(nx, ny));
      }
    }
    if(flag == false){
      cout << ti;
      return 0;
    }
    sort(t.begin(), t.end());
    // for(int j = 0; j < t.size(); j++){
    //   cout << ss.X << " " << ss.Y << " "<< get<0>(t[j]) << " " << get<1>(t[j]) << " " << get<2>(t[j]) << '\n';
    // }
    ss = {get<1>(t[0]), get<2>(t[0])};
    board[get<1>(t[0])][get<2>(t[0])] = 0;

    // for(int ird = 0; ird < N; ird++){
    //   for(int jrd = 0; jrd < N; jrd++){
    //     cout << board[ird][jrd] << " ";
    //   }
    //   cout << '\n';
    // }
    // cout << big << '\n';
    ti += vis[ss.X][ss.Y] - 1;
    tp++;
    if(tp == big){
      big++;
      tp = 0;
    }
  }
  cout << ti;
}
