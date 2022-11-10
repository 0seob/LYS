#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int N, a;
  deque<int> v;
  scanf("%d",&N);
  for(int i = 0; i < N ; i++){
    v.push_back(i+1);
  }
  while(v.size() != 1){
    v.pop_front();
    a = v.front();
    v.pop_front();
    v.push_back(a);
    for(int i=0;i<v.size();i++){
    }
  }
  printf("%d\n",v[0]);
  return 0;
}
