#include <bits/stdc++.h>
#include <list>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  ll n, in, max = 0, str = 0, size, min = quot;
  stack<ll> st;
  while(1){
    cin >> n;
    if(n == 0) break;
    st.push(0);
    for(int i = 1; i <= n; i++){
      cin >> in;
      if(in < min) min = in;
      if(st.top() > in){
        while(st.size() > 1){
          str++;
          size = st.top() * str;
          if(size > max){
            max = size;
            h = st.top();
          }
          st.pop();
        }
      }
      str = 0;
      st.push(in);
    }
    if(min * n > max) max = min * n;
    cout << max << '\n';
  }
}
/*m[7] = 1 m[5] = 0 m[3] = 0
2 4 1 2 2 5 1
9 9 8 6 9 8 6 9 4 15
9 7 7 5 5 3 3 5 8 20
8 9 9 8 6 4 4 6 9 16
9 9
0
*/
