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

int board[52][52];
int cpy[52][52];
int vis[52][52];
int vcpy[52][52];

int dx[8] = {1, 0, -1 ,0};
int dy[8] = {0, 1, 0, -1};

int N, M, in, sz, cnt, num, ans = quot, cnt_1, full_of_virus, v_cnt;
bool flag;

deque<pair<int, int> > dq;
deque<pair<int, int> > two;
deque<deque<pair<int, int> > > com;

void comb(int n, int m, int i){
  //모든 조합의 수를 만들어 com에 집어 넣음
  if(n == 0 && m > 0){
    return;
  }
  if(m == 0){
    com.push_back(dq);
    return;
  }
  comb(n-1, m, i+1);
  dq.push_back(make_pair(two[i].X, two[i].Y));
  comb(n-1, m-1, i+1);
  dq.pop_back();
}

int main(int argc, char const *argv[]) {
  FASTIO();
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> in;
      board[i][j] = in;
      if(in == 2){
        two.push_back(make_pair(i, j));
        cnt++;
      }
      else if(in == 1){
        vis[i][j] = -1;
        cnt_1++;
      }
    }
  }
  full_of_virus = N*N - cnt_1;
  comb(cnt, M, 0);
  // cout << '\n';
  sz = com.size();
  for(int i = 0; i < sz; i++){
    memcpy(cpy, board, sizeof(board));
    memcpy(vcpy, vis, sizeof(vis));
    queue<pair<int, int> > q;
    v_cnt = cnt;
    flag = 0, num = 0;
    for(int j = 0; j < com[i].size(); j++){
      q.push(make_pair(com[i][j].X, com[i][j].Y));
      vcpy[com[i][j].X][com[i][j].Y] = 1;
    }
    while(!q.empty()){
      pair<int, int> cur = q.front(); q.pop();
      for(int dir = 0; dir < 4; dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if(board[nx][ny] == 1 || vcpy[nx][ny] != 0) continue;
        q.push(make_pair(nx, ny));
        // cout << v_cnt << " ";
        if(v_cnt < full_of_virus){
          if(board[nx][ny] != 2) v_cnt++;
          vcpy[nx][ny] = vcpy[cur.X][cur.Y] + 1;
        }
        else vcpy[nx][ny] = 1;
      }
    }
    for(int p = 0; p < N; p++){
      for(int q = 0; q < N; q++){
        if(vcpy[p][q] == 0){
          flag = 1;
          num = -1;
          break;
        }
        else num = max(num, vcpy[p][q]);
      }
      if(flag == 1) break;
    }
    if(num != -1) ans = min(num, ans);
  //   for(int p = 0; p < N; p++){
  //     for(int q = 0; q < N; q++){
  //       cout << vcpy[p][q] << " ";
  //     }
  //     cout << '\n';
  //   }
  //   cout << num << '\n';
  // }
  // cout << full_of_virus << '\n';
  }
  if(ans == quot) cout << -1;
  else  cout << ans - 1;
}
