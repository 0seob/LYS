#include <bits/stdc++.h>
#include <list>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  int n, a, max = 0, str = 0, size, min = quot;
  string in;
  queue<ll> qu;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> in;
    if(in == "push"){
      cin >> a;
      qu.push(a);
    }
    else if(in == "pop"){
      if(qu.empty()){
        cout << -1 << '\n';
        continue;
      }
      cout << qu.front() << '\n';
      qu.pop();
    }
    else if(in == "size"){
      cout << qu.size() << '\n';
    }
    else if(in == "empty"){
      cout << qu.empty() << '\n';
    }
    else if(in == "front"){
      if(qu.empty()){
        cout << -1 << '\n';
        continue;
      }
      cout << qu.front() << '\n';
    }
    else if(in == "back"){
      if(qu.empty()){
        cout << -1 << '\n';
        continue;
      }
      cout << qu.back() << '\n';
    }
  }
}
