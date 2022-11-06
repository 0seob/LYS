#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <list>
#include <tuple>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
#define X first
#define Y second
typedef long long ll;

using namespace std;

int board[305][305];
int arr[100005];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(int argc, char const *argv[]) {
  FASTIO();
  int N, K, M;
  cin >> N;
  vector<int> v;
  map<int, int> m;
  for(int i = 0; i < N; i++){
    cin >> K;
    m[K] = 1;
  }
  cin >> M;
  for(int i = 0; i < M; i++){
    cin >> K;
    if(m[K] == 1) cout << 1 << '\n';
    else cout << 0 << '\n';
  }
}