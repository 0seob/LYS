#include <bits/stdc++.h>
#define quot 1000000000
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  ll N, arr[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1}, ans[10] = {}, sum = 0;
  cin >> N;
  if(N == 1){
    cout << 9 << '\n';
    return 0;
  }
  for(int i = 1; i < N; i++){
    ans[0] = arr[1];
    for(int j = 1; j < 9; j++){
      ans[j] = (arr[j-1] + arr[j+1]) % quot;
    }
    ans[9] = arr[8];
    for(int j = 0; j < 10; j++){
      arr[j] = ans[j];
    }
  }
  for(int i = 0; i < 10; i++){
    sum += ans[i];
  }
  cout << sum % quot;
}

/*
0      1       2       3       4       5       6       7       8       9
 1   0   2   1   3   2   4   3   5   4   6   5   7   6   8   7   9   8
0 2   1 1 3 0 2 2 4 1 3 3 5 2 4 4 6 3 5 5 7 4 6 6 8 5 7 7 9 6 8 8   7 9
1, 8 2 / 0, 9 1
0 1 2 3 4 5 6 7 8 9
-------------------
0 1 1 1 1 1 1 1 1 1

1 1 2 2 2 2 2 2 2 1

1 3 3 4 4 4 4 4 3 2

3 4 7 7 8 8 8 7 6 3

4 10 11 15 15 16 15 14 10 6
9 17 32 61
*/
