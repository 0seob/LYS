#include <bits/stdc++.h>
#include <list>
#include <tuple>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
#define X first
#define Y second
typedef long long ll;

using namespace std;

int board[305][305];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int topni[5][10];
vector<vector<int> > temp, tp = {{-1, -1}, {-1, 2}, {6, 2}, {6, 2}, {6, -1}};

void rotate(int num, int clk){
  temp = tp;
  int left = 1, right = 1;;

  for(int i = 0; i < 2; i++){
    if(temp[num][i] == -1) continue;
    tp[num][i] += 8-clk;
    tp[num][i] %= 8;
  }

  if(left == 1 && 1 <= num - 1 && topni[num-1][temp[num-1][1]] != topni[num][temp[num][0]]){
    for(int i = 0; i < 2; i++){
      if(temp[num-1][i] == -1) continue;
      tp[num-1][i] += 8+clk;
      tp[num-1][i] %= 8;
    }
  }
  else left = 0;
  if(right == 1 && num + 1 <= 4 && topni[num+1][temp[num+1][0]] != topni[num][temp[num][1]]){
    for(int i = 0; i < 2; i++){
      if(temp[num+1][i] == -1) continue;
      tp[num+1][i] += 8+clk;
      tp[num+1][i] %= 8;
    }
  }
  else right = 0;

  if(left == 1 && 1 <= num - 2 && topni[num-2][temp[num-2][1]] != topni[num-1][temp[num-1][0]]){
    for(int i = 0; i < 2; i++){
      if(temp[num-2][i] == -1) continue;
      tp[num-2][i] += 8-clk;
      tp[num-2][i] %= 8;
    }
  }
  else left = 0;
  if(right == 1 && num + 2 <= 4 && topni[num+2][temp[num+2][0]] != topni[num+1][temp[num+1][1]]){
    for(int i = 0; i < 2; i++){
      if(temp[num+2][i] == -1) continue;
      tp[num+2][i] += 8-clk;
      tp[num+2][i] %= 8;
    }
  }
  else right = 0;

  if(left == 1 && 1 <= num - 3 && topni[num-3][temp[num-3][1]] != topni[num-2][temp[num-2][0]]){
    for(int i = 0; i < 2; i++){
      if(temp[num-3][i] == -1) continue;
      tp[num-3][i] += 8+clk;
      tp[num-3][i] %= 8;
    }
  }
  if(right == 1 && num + 3 <= 4 && topni[num+3][temp[num+3][0]] != topni[num+2][temp[num+2][1]]){
    for(int i = 0; i < 2; i++){
      if(temp[num+3][i] == -1) continue;
      tp[num+3][i] += 8+clk;
      tp[num+3][i] %= 8;
    }
  }
}

int main(int argc, char const *argv[]) {
  // FASTIO();
  int K, num, clk, sum = 0;
  vector<pair<int, int> > v;
  for(int i = 1; i <= 4; i++){
    for(int j = 0; j < 8; j++){
      scanf("%1d", &topni[i][j]);
    }
  }

  cin >> K;
  for(int i = 0; i < K; i++){
    scanf("%d %d", &num, &clk);
    v.push_back(make_pair(num, clk));
  }
  for(int i = 0; i < K; i++){
    rotate(v[i].X, v[i].Y);
  }
  if(topni[1][(tp[1][1] + 6) % 8] == 1) sum += 1;
  if(topni[2][(tp[2][0] + 2) % 8] == 1) sum += 2;
  if(topni[3][(tp[3][0] + 2) % 8] == 1) sum += 4;
  if(topni[4][(tp[4][0] + 2) % 8] == 1) sum += 8;
  printf("%d\n", sum);
}
