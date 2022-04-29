#include <bits/stdc++.h>
#include <list>
#include <tuple>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
#define X first
#define Y second
typedef long long ll;

using namespace std;

int board[10][10];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<pair<int, int> > > v = {{}, {}, {}, {}, {}, {}};

int main(int argc, char const *argv[]) {
  FASTIO();
  int N, M, in;
  cin >> N >> M;
  // v[1].push_back(make_pair(N, M));
  // for(int i = 1; i < 6; i++) cout << v[i].size() << " ";
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> in;
      cout << 1;
      if(in % 6) v[in].push_back(make_pair(i, j));
      board[i][j] = in;
    }
  }
  for(int i = 1; i < 6; i++) cout << v[i].size() << " ";
}
