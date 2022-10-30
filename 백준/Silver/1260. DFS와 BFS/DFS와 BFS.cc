#include <bits/stdc++.h>
#define quot 1000000000
#define FASTIO() ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int arr[1001][1001] = {};

void dfs(int N, int V, int* visit){
  visit[V] = 1;
  cout << V << " ";
  for(int i = 1; i <= N; i++){
    if(visit[i] == 0 && arr[V][i] == 1){
      dfs(N, i, visit);
    }
  }
}

queue<int> q;

void bfs(int N, int V, int* visit){
  visit[V] = 1;
  q.push(V);
  while(!q.empty()){
    int val = q.front();
    cout << val << " ";
    q.pop();
    for(int i = 1; i <= N; i++){
      if(visit[i] == 0 && arr[val][i] == 1){
        q.push(i);
        visit[i] = 1;
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  FASTIO();
  int N, M, V, a, b;
  cin >> N >> M >> V;
  for(int i = 0; i < M; i++){
    cin >> a >> b;
    arr[a][b] = 1;
    arr[b][a] = 1;
  }
  int visit1[1001] = {};
  dfs(N, V, visit1);
  cout << '\n';
  int visit2[1001] = {};
  bfs(N, V, visit2);
}
