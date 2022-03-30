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

int main(int argc, char const *argv[]) {
  FASTIO();
  int t;
  cin >> t;
  while(t--){
    int n, k, di, re, ans;
    cin >> n >> k;
    di = k / (n-1);
    k % (n-1) == 0 ? re = k % (n-1) - 1 : re = k % (n-1);
    ans = di * n + re;
    cout << ans << '\n';
  }
}
