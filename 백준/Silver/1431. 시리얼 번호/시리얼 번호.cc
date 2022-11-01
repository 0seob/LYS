#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <functional>

using namespace std;

int main(){
  int N,sum;
  string S;
  scanf("%d",&N);
  vector<pair<int, pair<int,string> > > v(1000000);
  for(int i=0;i<N;i++){
    cin >> v[i].second.second;
    v[i].first = v[i].second.second.length();
    for(int j=0;j<v[i].first;j++){
      if(v[i].second.second[j] < 'A')
        sum += v[i].second.second[j] - '0';
    }
    v[i].second.first = sum;
    sum = 0;
  }
  sort(v.begin(),v.begin()+N);
  for(int i=0;i<N;i++){
    printf("%s\n",v[i].second.second.c_str());
  }
}
