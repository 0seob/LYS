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

int sum = 0;

void zzz(int N, int r, int c){
  if(N == 0) return;
  int na = 1 << (N-1);
  if(r/na == 0 && c/na == 0){
    zzz(N - 1, r % na, c % na);
  }
  else if(r/na == 0 && c/na == 1){
    sum += na * na;
    zzz(N - 1, r % na, c % na);
  }
  else if(r/na == 1 && c/na == 0){
    sum += na * na * 2;
    zzz(N - 1, r % na, c % na);
  }
  else{
    sum += na * na * 3;
    zzz(N - 1, r % na, c % na);
  }
}

int main(int argc, char const *argv[]) {
  FASTIO();
  int N, r, c;
  cin >> N >> r >> c;
  zzz(N, r, c);
  cout << sum;
}
