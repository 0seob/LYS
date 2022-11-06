#include <cstdio>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;

int n,m;
vector<vector<pair<int, int> > > mat(20001);
//<도착점,비용>
vector<int> dijkstra(int s){
  priority_queue<pair<int, int>,vector<pair<int, int> >,greater<pair<int, int> > > pq;
  pq.push(make_pair(0,s));
  vector<int> dist(n+1,INF);
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
  scanf("%d %d",&n,&m);
  for(int i=0;i<m;i++){
    int u,v,w;
    scanf("%d %d %d",&u,&v,&w);
    mat[u].push_back(make_pair(v,w));
  }
  int a,b;
  scanf("%d %d",&a,&b);
  vector<int> dist = dijkstra(a);
  printf("%d\n",dist[b]);
}
