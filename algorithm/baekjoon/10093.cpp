#include <bits/stdc++.h>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  ll A, B, num;
  cin >> A >> B;
  if(A > B) {
    ll tmp = A;
    A = B;
    B = tmp;
  }
  if(A==B) {
    cout << "0" << endl;
    return 0;
  }
  num = B - A - 1;
  cout << num << '\n';
  for(int i = 1; i <= num; i++){
    cout << A + i << " ";
  }
}
