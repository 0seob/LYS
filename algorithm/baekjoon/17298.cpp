#include <bits/stdc++.h>
#include <list>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  int N, in, cnt = 0, sum = 0;
  cin >> N;
  stack<int> st, idx;
  vector<int> v(N);
  fill(v.begin(), v.end(), -1);
  for(int i = 0; i < N; i++){
    cin >> in;
    while(!st.empty() && st.top() < in){
      st.pop();
      v[idx.top()] = in;
      idx.pop();
    }
    st.push(in); idx.push(i);
  }
  for(int i = 0; i < N; i++) cout << v[i] << " ";
}
