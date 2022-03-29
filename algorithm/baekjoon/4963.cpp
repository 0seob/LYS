#include <bits/stdc++.h>
#include <list>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  int N, in, cnt = 0;
  int isprime[1005] = {};
  cin >> N;
  for(int i = 0; i < 1005; i++){
    isprime[i] = 1;
  }
  isprime[1] = 0;
  for(int i = 2; i < 1005; i++){
    if(isprime[i] == 1){
      for(int j = i + i; j < 1005; j+=i){
        isprime[j] = 0;
      }
    }
  }
  for(int i = 0; i < N; i++){
    cin >> in;
    if(isprime[in] == 1) cnt++;
  }
  cout << cnt;
}
