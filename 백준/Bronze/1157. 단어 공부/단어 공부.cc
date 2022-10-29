#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int cnt = 1, max = 1, ans = 0, index;
  string N;
  cin >> N;
  transform(N.begin(), N.end(), N.begin(), ::toupper);
  sort(N.begin(), N.end());
  for(int i = 1; i < N.length(); i++){
    if(N[i-1] == N[i]) cnt++;
    if(i == N.length()-1){
      if(cnt > max){
        index = i-1;
        ans = 0;
      }
      else if(cnt == max) ans = -1;
      break;
    }
    if(N[i-1] != N[i]){
      if(cnt > max){
        max = cnt;
        index = i-1;
        ans = 0;
      }
      else if(cnt == max) ans = -1;
      cnt = 1;
    }
  }
  if(ans == -1) cout << "?";
  else if(N.length() == 1) cout << N;
  else cout << N[index];
  return 0;
}