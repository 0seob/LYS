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
  int T, in, n, temp1 = 0, temp2 = 0, temp3 = 0;
  cin >> T;
  while(T--){
    map<int, int> m;
    int ok = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
      cin >> in;
      if(m.find(in) == m.end()) m.insert(make_pair(in, 1));
      else m.find(in)->Y++;
    }
    for(auto iter = m.begin(); iter != m.end(); ++iter){
      if(ok == 1) continue;
      if(iter->Y >= 3){
        cout << iter->X << '\n';
        ok = 1;
      }
    }
    if(ok == 0) cout << -1 << '\n';
  }
}
