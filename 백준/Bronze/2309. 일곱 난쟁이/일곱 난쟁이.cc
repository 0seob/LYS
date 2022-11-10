#include <bits/stdc++.h>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  int n, sum = 0, a, b, val;
  vector<int> v;
  for(int i = 0; i < 9; i++){
    cin >> n;
    v.push_back(n);
    sum += n;
  }
  sort(v.begin(), v.end());
  for(int i = 0; i < 8; i++){
    for(int j = i + 1; j < 9; j++){
      val = sum - v[i] - v[j];
      if(val == 100){
        a = i;
        b = j;
      }
    }
  }
  for(int i = 0; i < 9; i++){
    if(i != a && i != b) cout << v[i] << '\n';
  }
}
