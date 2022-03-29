#include <bits/stdc++.h>
#include <list>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  int K, n, val, ans = 0;
  stack<int> st;
  cin >> K;
  for(int i = 0; i < K; i++){
    cin >> n;
    if(n == 0) st.pop();
    else st.push(n);
  }
  int num = st.size();
  for(int i = 0; i < num; i++){
    val = st.top();
    st.pop();
    ans += val;
  }
  cout << ans;
}
