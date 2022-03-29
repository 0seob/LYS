#include <bits/stdc++.h>

using namespace std;

int maxval = -1000000000, minval = 1000000000, i = 0;
vector<char> result;

void dfs(int N, int* A, int* B, int ans){

  if(i == N-1){
    //2cout << "answer is " << ans << "\n";
    if(ans > maxval) maxval = ans;
    if(ans < minval) minval = ans;
    return;
  }

  if(B[0] != 0){
    B[0] -= 1;
    ans += A[i+1];
    //cout << "0" << "\n";
    i += 1;
    dfs(N, A, B, ans);
    i -= 1;
    ans -= A[i+1];
    B[0] += 1;
  }
  if(B[1] != 0){
    B[1] -= 1;
    ans -= A[i+1];
    //cout << "1" << "\n";
    i += 1;
    dfs(N, A, B, ans);
    i -= 1;
    ans += A[i+1];
    B[1] += 1;
  }
  if(B[2] != 0){
    B[2] -= 1;
    ans *= A[i+1];
    //cout << "2" << "\n";
    i += 1;
    dfs(N, A, B, ans);
    i -= 1;
    ans /= A[i+1];
    B[2] += 1;
  }
  if(B[3] != 0){
    B[3] -= 1;
    ans /= A[i+1];
    int rem = ans % A[i+1];
    //cout << "3" << "\n";
    i += 1;
    dfs(N, A, B, ans);
    i -= 1;
    ans *= A[i+1];
    ans += rem;
    B[3] += 1;
  }

}

int main(int argc, char const *argv[]) {
  int N, A[11] = {}, B[4] = {};
  cin >> N;
  for(int j = 0; j < N; j++){
    cin >> A[j];
  }
  cin >> B[0] >> B[1] >> B[2] >> B[3];
  dfs(N, A, B, A[0]);
  cout << maxval << "\n" << minval;
}
