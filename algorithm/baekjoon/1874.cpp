#include <bits/stdc++.h>
#include <list>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  int N, in, cnt = 1, max = 0;
  string ans;
  stack<int> st;
  cin >> N;
  for(int i = 1; i <= N; i++){
    cin >> in;
    while(cnt <= in){
      st.push(cnt);
      cnt++;
      ans+="+\n";
    }
    if(st.top() != in){
      cout << "NO";
      return 0;
    }
    st.pop();
    ans+="-\n";
  }
  cout << ans;
}
