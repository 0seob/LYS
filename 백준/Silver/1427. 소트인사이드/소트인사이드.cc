#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, a, c, i = 0;
  vector <int> v;
  cin >> N;
  while(1){
    a = N % 10;
    v.push_back(a);
    N /= 10;
    i++;
    if(N == 0) break;
  }
  sort(v.rbegin(), v.rend());

  for(int i = 0; i < v.size(); i++){
    cout << v[i];
  }
  return 0;
}
