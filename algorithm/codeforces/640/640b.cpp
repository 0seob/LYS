#include <bits/stdc++.h>
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
  int t;
  cin >> t;
  while(t--){
    int n, k;
    vector<int> v;
    cin >> n >> k;
    if(n % 2 == 0 && n / 2 >= k){
      while(--k){
        n -= 2;
        v.push_back(2);
      }
      v.push_back(n);
    }
    else{
      while(--k){
        n -= 1;
        v.push_back(1);
      }
      if(n % 2 == 0 || n < 0){
        cout << "NO\n";
        continue;
      }
      v.push_back(n);
    }
    cout << "YES\n";
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << "\n";
  }
}
