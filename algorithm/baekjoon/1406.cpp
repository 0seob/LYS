#include <bits/stdc++.h>
#include <list>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  int M;
  list<char> li;
  char com, ch;
  string s;
  cin >> s;
  auto iter = li.begin();
  for(int i = 0; i < s.size(); i++){
    li.push_back(s[i]);
    iter++;
  }
  iter++;
  cin >> M;
  for(int i = 0; i < M; i++){
    cin >> com;
    if(com == 'P'){
      cin >> ch;
      li.insert(iter, ch);
    }
    else if(com == 'L' && iter != li.begin()) iter--;
    else if(com == 'D' && iter != li.end()) iter++;
    else if(com == 'B' && iter != li.begin()) iter = li.erase(--iter);
  }
  for(iter = li.begin(); iter != li.end(); iter++){
    cout << *iter;
  }
}
