#include <bits/stdc++.h>
#define quot 1000000000
#define FASTIO() ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  int N, val;
  queue<int> q;
  string com, sub;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> com;
    if(com == "front"){
      if(q.size() != 0) cout << q.front() << '\n';
      else cout << -1 << '\n';
    }
    else if(com == "back"){
      if(q.size() != 0) cout << q.back() << '\n';
      else cout << -1 << '\n';
    }
    else if(com == "size") cout << q.size() << '\n';
    else if(com == "empty") cout << q.empty() << '\n';
    else if(com == "pop") {
      if(q.size() != 0){
        val = q.front();
        q.pop();
        cout << val << '\n';
      }
      else cout << -1 << '\n';
    }
    else {
      cin >> val;
      q.push(val);
    }
  }
}
