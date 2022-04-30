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

int board[12][12];
int gureum[12][12];
int cnt[12][12];

int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {-1, 0, 1, -1, -1, 0, 1, 1};

typedef struct dice_struct{
  int top, bottom, left, right, front, back;
}DS;

int N, M, K, x, y, z, g, num, ans;
bool flag;

deque< deque< deque<int> > > tree(11, deque< deque<int> >(11));

void ss(int N){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(tree[i][j].size() >= 2){
        int k = 0;
        while(board[i][j] - tree[i][j][k] >= 0 && k < tree[i][j].size()){
          board[i][j] -= tree[i][j][k];
          tree[i][j][k]++;
          k++;
        }
        for(int l = tree[i][j].size() - 1; l >= k; l--){
          board[i][j] += tree[i][j][l]/2;
          tree[i][j].pop_back();
        }
      }
      else if(tree[i][j].size() == 1){
        if(board[i][j] - tree[i][j][0] < 0){
          board[i][j] += tree[i][j][0]/2;
          tree[i][j].pop_back();
        }
        else {
          board[i][j] -= tree[i][j][0];
          tree[i][j][0] += 1;
        }
      }
    }
  }
}

void fw(int N){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(tree[i][j].size()){
        int size = tree[i][j].size();
        for(int k = 0; k < size; k++){
          if(tree[i][j][k] % 5 == 0){
            for(int dir = 0; dir < 8; dir++){
              int nx = i + dx[dir];
              int ny = j + dy[dir];
              if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
              tree[nx][ny].push_front(1);
            }
          }
        }
      }
      board[i][j] += gureum[i][j];
    }
  }
}

int main(int argc, char const *argv[]) {
  FASTIO();
  cin >> N >> M >> K;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> gureum[i][j];
      board[i][j] = 5;
    }
  }

  for(int i = 0; i < M; i++){
    cin >> x >> y >> z;
    tree[x-1][y-1].push_back(z);
    cnt[x-1][y-1]++;
  }

  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      if(cnt[i][j] >= 2) sort(tree[i][j].begin(), tree[i][j].end());

  for(int i = 0; i < K; i++){
    ss(N);
    fw(N);
  }

  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      ans += tree[i][j].size();

  cout << ans;
}
