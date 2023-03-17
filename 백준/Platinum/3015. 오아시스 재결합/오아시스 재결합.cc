#include <bits/stdc++.h>
#include <list>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  ll N, in, cnt = 0, max = 0;
  cin >> N;
  stack<ll> st;
  map<ll, ll> m;
  for(int i = 0; i < N; i++){
    cin >> in;
    while(!st.empty() && st.top() < in){
      cnt++;
      m[st.top()] = 0;
      st.pop();
    }
    if(!st.empty() && st.top() == in) {
      if(m.find(st.top()) == m.end()) m[st.top()] = 1;
      else m[st.top()]++;
      cnt += m[st.top()];
    }
    if(max > in) cnt++;
    if(max < in) max = in;
    st.push(in);
  }
  cout << cnt;
}