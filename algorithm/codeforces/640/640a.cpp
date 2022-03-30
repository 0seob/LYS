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
    int n, cnt = 1;
    vector<int> v;
    cin >> n;
    while(n != 0){
      if(n%10 != 0) v.push_back(cnt*(n%10));
      cnt *= 10;
      n /= 10;
    }
    cout << v.size() << '\n';
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << '\n';
  }
}
