#include <bits/stdc++.h>
#include <list>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  int N, M, in, arr[50] = {}, val = 0, sum = 0, ans = 0, temp, cnt = 0, cnt1 = 0;
  deque<int> dq;
  cin >> N >> M;
  for(int i = 1; i <= N; i++){
    dq.push_back(i);
  }
  for(int i = 0; i < M; i++){
    cin >> in;
    arr[i] = in;
  }
  for(int i = 0; i < M; i++){
    if(arr[i] != 1){
      if(arr[i] <= (dq.size()+1)/2){
        temp = arr[i] - 1;
        ans += temp;
        for(int j = i; j < M; j++){
          arr[j] -= temp;
          if(arr[j] < 1) arr[j] += dq.size();
        }
      }
      else{
        temp = dq.size() + 1 - arr[i];
        ans += temp;
        for(int j = i; j < M; j++){
          arr[j] += temp;
          if(arr[j] > dq.size()) arr[j] -= dq.size();
        }
      }
    }
    for(int j = i; j < M; j++) arr[j]--;
    dq.pop_front();
  }
  cout << ans;
}
