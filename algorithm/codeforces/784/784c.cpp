#include <bits/stdc++.h>
#include <map>
#include <list>
#include <tuple>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
#define X first
#define Y second
typedef long long ll;

using namespace std;

int board[305][305];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(int argc, char const *argv[]) {
  FASTIO();
  int T, in, n, fir, sec;
  cin >> T;
  while(T--){
    int ok = 1;
    cin >> n;
    cin >> fir;
    cin >> sec;
    for(int i = 2; i < n; i++){
      cin >> in;
      if(ok == 0) continue;
      if(i % 2 == 0){
        if(in % 2 != fir % 2){
          cout << "NO\n";
          ok = 0;
        }
      }
      else {
        if(in % 2 != sec % 2){
          cout << "NO\n";
          ok = 0;
        }
      }
    }
    if(ok == 1) cout << "YES\n";
  }
}
