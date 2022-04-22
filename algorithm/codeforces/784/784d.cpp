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
vector<string> FS = {"RRR", "BBB", "WRW", "WBW", "WWB", "WWR", "WRR", "WBB", "RWR", "RWB", "BWR", "BWR"};

int main(int argc, char const *argv[]) {
  FASTIO();
  int T, in, n, fir, sec;
  string s;
  cin >> T;
  while(T--){
    int ok = 1;
    cin >> n;
    cin >> s;
    if(n == 1) cout << "NO\n";
    else if(n == 2 && !(s == "BR" || s == "RB")) cout << "NO\n";
    else{
      for(int i = 0; i < n - 3; i++){
        if(ok == 0) continue;
        if(s.substr(i, 3) == "RRR" || s.substr(i, 3) == "BBB" || s.substr(i, 3) == "WBW" || s.substr(i, 3) == "WRW" || s.substr(i, 4) == "WBBW" || s.substr(i, 4) == "WRRW"){
          cout << "NO\n";
          ok = 0;
        }
      }
      if(ok == 1){
        for(int i = 0; i < 12; i++){
          if(s.substr(n-3, 3) == FS[i]){
            cout << "NO\n";
            ok = 0;
          }
        }
      }
      if(ok == 1) cout << "YES\n";
    }
  }
}
// 27
//
//
// RRB RBR RBB RBW 4
// BBR BRB BRR BRW 4 무조건됨
// WRB WBR WWW 3
//
// WWB WWR WRR WBB  유예
// RWR RWW RWB RRW
// BWR BWW BWR BBW
//
// WRW WBW
// RRR  무조건안됨
// BBB
//
// WRRW
// WBBW
