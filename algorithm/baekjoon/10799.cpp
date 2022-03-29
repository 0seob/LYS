#include <bits/stdc++.h>
#include <list>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  string s;
  cin >> s;
  int len = s.length(), cnt = 0, cl = 0;
  stack<char> st;
  for(int i = 0; i < len; i++){
    if(s[i] == '('){
      st.push(s[i]);
      cl = 0;
    }
    else if(cl == 0){
      st.pop();
      cnt += st.size();
      cl = 1;
    }
    else if(cl == 1){
      st.pop();
      cnt++;
    }
  }
  cout << cnt;
}
