#include <bits/stdc++.h>
#include <list>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  int N, cnt = 0;
  cin >> N;
  for(int i = 0; i < N; i++){
    stack<int> st;
    string s;
    cin >> s;
    int len = s.length();
    for(int i = 0; i < len; i++){
      if(st.empty()) st.push(s[i]);
      else{
        if(s[i] == st.top()) st.pop();
        else st.push(s[i]);
      }
    }
    if(st.size() == 0) cnt++;
  }
  cout << cnt;
}
