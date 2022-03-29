#include <bits/stdc++.h>
#include <list>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  ll N, in, cnt = 0, sum = 0;
  cin >> N;
  stack<ll> st;
  st.push(0);
  for(int i = 1; i <= N; i++){
    cin >> in;
    while(st.top() != 0 && st.top() <= in){
      st.pop();
      sum += cnt;
      cnt = 0;
    }
    st.push(in);
    cnt += st.size() - 2;
    if(i == N) sum += cnt;
  }
  cout << sum;
}
