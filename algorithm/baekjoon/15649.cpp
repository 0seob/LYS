#include <bits/stdc++.h>
#define quot 1000000000
typedef long long ll;

using namespace std;

vector<int> v;
void dfs(int N, int M, int *arr){
  if(v.size() == M){
    for(int i = 0; i < M; i++){
      cout << v[i] << " ";
    }
    cout << "\n";
  };
  for(int i = 0; i < N; i++){
    if(arr[i] == 0) continue;
    v.push_back(i+1);
    arr[i] -= 1;
    dfs(N, M, arr);
    arr[i] += 1;
    v.pop_back();
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M, arr[8] = {1, 1, 1, 1, 1, 1, 1, 1};
  cin >> N >> M;
  dfs(N, M, arr);
}
