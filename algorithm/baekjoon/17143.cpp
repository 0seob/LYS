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

int dx[5] = {0, -1, 1, 0 ,0}; //위 아 오 왼
int dy[5] = {0, 0, 0, 1, -1};

int R, C, M, r, c, s, d, z, x, y, ans, temp, sum;
bool flag;

deque<deque<deque<tuple<int, int, int> > > > shark(105, deque<deque<tuple<int, int, int> > >(105));
deque<tuple<int, int, int, int, int> > state;

int fisher(int in){
  for(int i = 1; i <= R; i++){
    if(shark[i][in].size()){
      int num = get<2>(shark[i][in][0]);
      shark[i][in].pop_back();
      return num;
    }
  }
  return 0;
}

void move(int sh){
  deque<tuple<int, int, int, int, int> > state;
  for(int i = 1; i <= R; i++){
    for(int j = 1; j <= C; j++){
      if(sh > 0 && shark[i][j].size()){
        sh -= 1, x = i, y = j;
        // cout << sh << " " << i << " " << j << '\n';
        tuple<int, int, int> cur = shark[i][j][0];
        shark[i][j].pop_back();
        int fast = get<0>(cur);
        int news = get<1>(cur);
        int big = get<2>(cur);
        int fst = fast;
        // cout << fast << " " << news << " " << big << " " <<  x << " " << y << '\n';
        temp = 0;
        if(news == 1){
          if(i - fast < 1){
            temp = i - 1;
            fast -= temp;
            news = 2;
          }
          else fast += R - i;
        }
        else if(news == 2){
          if(i + fast > R){
            temp = R - i;
            fast -= temp;
            news = 1;
          }
          else fast += i - 1;
        }
        else if(news == 3){
          if(j + fast > C){
            temp = C - j;
            fast -= temp;
            news = 4;
          }
          else fast += j - 1;
        }
        else{
          if(j - fast < 1){
            temp = j - 1;
            fast -= temp;
            news = 3;
          }
          else fast += C - j;
        }

        if(news <= 2){
          while(fast >= R){
            fast -= R - 1;
            if(news % 2 == 0) news -= 1;
            else news += 1;
          }
        }
        else{
          while(fast >= C){
            fast -= C - 1;
            if(news % 2 == 0) news -= 1;
            else news += 1;
          }
        }

        if(news == 1) x = R - fast;
        else if(news == 2) x = 1 + fast;
        else if(news == 3) y = 1 + fast;
        else y = C - fast;
        // cout << fast << " " << news << " " << big << " " <<  x << " " << y << '\n';
        // cout << '\n';
        // cout << cpy[x][y].size() << '\n';
        state.push_back(make_tuple(x, y, fst, news, big));
      }
    }
  }
  int sz = state.size();
  for(int i = 0; i < sz; i++){
    if(shark[get<0>(state[i])][get<1>(state[i])].size() == 0) shark[get<0>(state[i])][get<1>(state[i])].push_back(make_tuple(get<2>(state[i]), get<3>(state[i]), get<4>(state[i])));
    else{
      if(get<2>(shark[get<0>(state[i])][get<1>(state[i])][0]) < get<4>(state[i])){
        shark[get<0>(state[i])][get<1>(state[i])].pop_back();
        M -= 1;
        shark[get<0>(state[i])][get<1>(state[i])].push_back(make_tuple(get<2>(state[i]), get<3>(state[i]), get<4>(state[i])));
      }
    }
  }
}

// void erase(){
//   for(int i = 1; i <= R; i++){
//     for(int j = 1; j <= C; j++){
//       if(shark[i][j].size() >= 2){
//         sort(shark[i][j].begin(), shark[i][j].end());
//         for(int k = 0; k < shark[i][j].size() - 1; k++) shark[i][j].pop_front();
//         for(auto iter = state.begin(); iter != state.end(); iter++) if(state[iter].X = i && state[iter].Y = j) state.erase(iter);
//       }
//     }
//   }
// }

int main(int argc, char const *argv[]) {
  FASTIO();
  cin >> R >> C >> M;
  for(int i = 0; i < M; i++){
    cin >> r >> c >> s >> d >> z;
    shark[r][c].push_back(make_tuple(s, d, z)); //속력, 방향, 크기
  }
  for(int i = 1; i <= C; i++){
    // cout << i << '\n';
    ans = fisher(i);
    // cout << ans << '\n';
    if(ans != 0){
      M -= 1;
      sum += ans;
    }
    move(M);
    // erase();
  }
  cout << sum;
}
