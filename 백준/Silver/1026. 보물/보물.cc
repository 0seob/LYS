#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int N, sum = 0, a, b;
  vector <int> v1;
  vector <int> v2;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> a;
    v1.push_back(a);
  }
  for(int j = 0; j < N; j++){
    cin >> b;
    v2.push_back(b);
  }
  sort(v1.begin(), v1.end());
  sort(v2.rbegin(), v2.rend());
  for(int k = 0; k < N; k++){
    sum += (v1[k] * v2[k]);
  }
  cout << sum;
  return 0;
}
