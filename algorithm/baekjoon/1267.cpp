#include <bits/stdc++.h>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  int N, pr, sumy = 0, summ = 0;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> pr;
    int yq = pr / 30;
    int yp = (yq + 1) * 10;
    sumy += yp;
    int mq = pr / 60;
    int mp = (mq + 1) * 15;
    summ += mp;
  }
  if(sumy < summ) cout << "Y" << " " << sumy;
  else if(sumy > summ) cout << "M" << " " << summ;
  else cout << "Y" << " " << "M" << " " << sumy;
}
