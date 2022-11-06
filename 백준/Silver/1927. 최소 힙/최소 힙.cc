#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int,vector<int>,greater<int> > pq;

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int X;
    scanf("%d",&X);
    if(X==0){
      if(pq.empty())
        printf("0\n");
      else{
        printf("%d\n",pq.top());
        pq.pop();
      }
    }
    else{
      pq.push(X);
    }
  }
}