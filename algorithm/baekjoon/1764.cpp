#include <bits/stdc++.h>

using namespace std;

bool divide(string a, vector<string> &nosee){
  int mid = nosee.size()/2;
  int low = 0;
  int high = nosee.size()-1;
  while(low <= high){
    if(a < nosee[mid]){
      high = mid - 1;
      mid = (high + low)/2;
    }
    else if(a > nosee[mid]){
      low = mid + 1;
      mid = (high + low)/2;
    }
    else return true;
  }
  return false;
}

int main(int argc, char const *argv[]) {
  int N, M, cnt = 0;
  string temp;
  vector<string> nohear;
  vector<string> nosee;
  vector<string> v;

  cin >> N >> M;

  for(int i = 0; i < N; i++){
    cin >> temp;
    nohear.push_back(temp);
  }
  for(int i = 0; i < M; i++){
    cin >> temp;
    nosee.push_back(temp);
  }

  sort(nohear.begin(), nohear.end());
  sort(nosee.begin(), nosee.end());

  for(int i = 0; i < N; i++){
    if(divide(nohear[i], nosee) == 1){
      cnt++;
      v.push_back(nohear[i]);
    }
  }

  cout << cnt << "\n";
  for(int i = 0; i < v.size(); i++){
    cout << v[i] << "\n";
  }

  return 0;
}
