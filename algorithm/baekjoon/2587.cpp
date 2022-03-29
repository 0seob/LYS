#include <bits/stdc++.h>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  int n, sum = 0;
  vector<int> v;
  for(int i = 0; i < 5; i++){
    cin >> n;
    v.push_back(n);
    sum += n;
  }
  sort(v.begin(), v.end());
  cout << sum/5 << '\n' << v[2];
}
