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

int cnt = 0;

void hanoi(int a, int b, int c){
  if(c == 0) return ;
  hanoi(a, 6-a-b, c-1);
  cout << a << " " << b << '\n';
  hanoi(6-a-b, b, c-1);
}

int main(int argc, char const *argv[]) {
  FASTIO();
  int N;
  cin >> N;
  cout << (1<<N) - 1 << '\n';
  hanoi(1, 3, N);
}
