#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <functional>

using namespace std;

int main(){
  int N;
  string S;
  scanf("%d",&N);
  vector<pair<int,string> > v(1000000);
  for(int i=0;i<N;i++){
    cin >> v[i].second;
    v[i].first = v[i].second.length();
  }
  sort(v.begin(),v.begin()+N);
  for(int i=0;i<N;i++){
    if(S!=v[i].second){
      printf("%s\n",v[i].second.c_str());
    }
    S=v[i].second;
  }
}
