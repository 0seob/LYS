#include <cstdio>
#include <queue>

using namespace std;

priority_queue<int,vector<int>,greater<int> > pq;

int main(){
  int N,ans=0;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int X;
    scanf("%d",&X);
    pq.push(X);
  }
  while(pq.size()>1){
    int A = pq.top();
    pq.pop();
    int B = pq.top();
    pq.pop();
    pq.push(A+B);
    ans+=(A+B);
  }
  printf("%d\n",ans);
}
