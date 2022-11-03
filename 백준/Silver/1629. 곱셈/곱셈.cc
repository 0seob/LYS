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

int idx = 0;

ll compute(ll a, ll b, ll c){
  if(b == 1) return a % c;
  else{
    ll ans = compute(a, b/2, c);
    ans = ans * ans % c;
    if(b % 2 == 0)
      return ans;
    else
      return ans * a % c;
  }
}

int main(int argc, char const *argv[]) {
  FASTIO();
  ll A, B, C;
  cin >> A >> B >> C;
  cout << compute(A, B, C);
}
