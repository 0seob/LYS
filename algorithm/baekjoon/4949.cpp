#include <bits/stdc++.h>
#include <list>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  while(1){
    stack<char> st;
    int no = 0;
    string s;
    getline(cin, s);
    if(s == ".") break;
    for(int i = 0; i < s.length(); i++){
      if(s[i] == '(' || s[i] == '[') st.push(s[i]);
      else if(s[i] == ')' || s[i] == ']'){
        if(st.size() == 0){
          cout << "no\n";
          no = 1;
          break;
        }
        else if(s[i] == ')' && st.top() == '(') st.pop();
        else if(s[i] == ']' && st.top() == '[') st.pop();
        else{
          cout << "no\n";
          no = 1;
          break;
        }
      }
    }
    if(no != 1 && st.size() != 0){
      cout << "no\n";
      continue;
    }
    if(no != 1) cout << "yes\n";
  }
}
