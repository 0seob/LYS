#include <bits/stdc++.h>
#include <list>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
#define X first
#define Y second
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  string s, str, str2;
  cin >> s;
  stack<char> st;
  int temp = 1, ans = 0;
  for(int i = 0; i < s.length(); i++){
    if(s[i] == '('){
      temp *= 2;
      st.push(s[i]);
    }
    else if(s[i] == '['){
      temp *= 3;
      st.push(s[i]);
    }
    else if(s[i] == ')'){
      if(st.empty() || st.top() == '['){
        cout << "0";
        return 0;
      }
      st.pop();
      if(i > 0 && s[i-1] == '(') ans += temp;
      temp /= 2;
    }
    else if(s[i] == ']'){
      if(st.empty() || st.top() == '('){
        cout << "0";
        return 0;
      }
      st.pop();
      if(i > 0 && s[i-1] == '[') ans += temp;
      temp /= 3;
    }
  }
  if(!st.empty()){
    cout << "0";
    return 0;
  }
  cout << ans;
}
