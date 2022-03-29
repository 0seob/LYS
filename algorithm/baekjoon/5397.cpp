#include <bits/stdc++.h>
#include <list>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  int T;
  cin >> T;
  for(int i = 0; i < T; i++){
    string L;
    cin >> L;
    list<char> li;
    auto iter = li.begin();
    for(auto c : L){
      if(c == '<'){
         if(iter != li.begin()) iter--;
      }
      else if(c == '>'){
        if(iter != li.end()) iter++;
      }
      else if(c == '-'){
        if(iter != li.begin()){
          iter--;
          iter = li.erase(iter);
        }
      }
      else li.insert(iter, c);
    }
    for(auto c : li){
      cout << c;
    }
    cout << '\n';
  }
}
