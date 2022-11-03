#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 200000000

using namespace std;

int N,E,ans=0;
vector<vector<pair<int, int> > > mat(20001);
//<도착점,비용>
vector<int> dijkstra(int s){
  priority_queue<pair<int, int>,vector<pair<int, int> >,greater<pair<int, int> > > pq;
  pq.push(make_pair(0,s));
  vector<int> dist(N+1,INF);
  dist[s]=0;
  while(!pq.empty()){
    int cost = pq.top().first, here = pq.top().second;
    pq.pop();
    if(dist[here] < cost) continue;
    for(int i=0;i<mat[here].size();i++){
      int nextcost = cost + mat[here][i].second;
      int there = mat[here][i].first;
      if(dist[there] > nextcost){
        dist[there] = nextcost;
        pq.push(make_pair(nextcost,there));
      }
    }
  }
  return dist;
}

int main(){
  scanf("%d %d",&N,&E);
  for(int i=0;i<E;i++){
    int u,v,w;
    scanf("%d %d %d",&u,&v,&w);
    mat[u].push_back(make_pair(v,w));
    mat[v].push_back(make_pair(u,w));
  }
  int p,q;
  scanf("%d %d",&p,&q);
  int ans1 = dijkstra(1)[p];
  int ans2 = dijkstra(p)[q];
  int ans3 = dijkstra(q)[N];
  int ans4 = dijkstra(1)[q];
  int ans5 = dijkstra(q)[p];
  int ans6 = dijkstra(p)[N];
  int ansp = ans1 + ans2 + ans3;
  int ansq = ans4 + ans5 + ans6;
  ans = min(ansp, ansq);
  if(ans>=INF)
    printf("-1\n");
  else printf("%d\n",ans);
}
