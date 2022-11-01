#include <bits/stdc++.h>
#include <list>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  int N, dp[1000005] = {};
  cin >> N;
  fill(dp, dp+1000005, 100000);
  dp[1] = 0;
  for(int i = 2; i <= N; i++){
    dp[i] = min(dp[i-1]+1, dp[i]);
    if(i % 3 == 0)  dp[i] = min(dp[i/3]+1, dp[i]);
    if(i % 2 == 0) dp[i] = min(dp[i/2]+1, dp[i]);
  }
  cout << dp[N];
}
