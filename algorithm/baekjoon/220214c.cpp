#include <bits/stdc++.h>
#include <list>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  ll t, n, in, temp;
  cin >> t;
  while(t--){
    ll cnt = 1;
    vector<ll> v;
    stack<ll> st;
    cin >> n;
    for(int i = 0; i < n; i++){
      cin >> in;
      while(v.size() != 0 && v.back() > in){
        cnt--;
        v.pop_back();
      }
      while(st.size() != 0 && st.top() < in){
        if(st.size() == 1){
          temp = st.top();
          v.push_back(temp);
          cnt++;
        }
        st.pop();
      }
      st.push(in);
    }
    cout << cnt << '\n';
  }
}
