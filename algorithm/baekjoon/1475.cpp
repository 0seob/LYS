#include <bits/stdc++.h>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  int N, arr[10] = {}, max = 0;
  cin >> N;
  while(N != 0){
    int val = N % 10;
    arr[val]++;
    N /= 10;
  }
  arr[6] = arr[6] + arr[9] + 1;
  arr[6] /= 2;
  arr[9] = 0;
  for(int i = 0; i < 10; i++){
    if(arr[i] > max) max = arr[i];
  }
  cout << max;
}
