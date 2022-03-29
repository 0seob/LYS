#include <bits/stdc++.h>
#include <list>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  int N, in,cnt = 0, oth = 0;
  cin >> N;
  stack<int> st, idx;
  st.push(0); idx.push(0);
  for(int i = 1; i <= N; i++){
    cin >> in;
    while(st.top() != 0 && st.top() < in){
      st.pop();
      idx.pop();
    }
    st.push(in);
    cout << idx.top() << " ";
    idx.push(i);
  }
}
