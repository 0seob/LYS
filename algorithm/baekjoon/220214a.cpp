#include <bits/stdc++.h>
#include <list>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  int t, n, in, temp, idx;
  cin >> t;
  while(t--){
    vector<int> v;
    cin >> n;
    for(int i = 0; i < n; i++){
      cin >> in;
      v.push_back(in);
    }
    for(int i = 0; i < n; i++){
      if(v[i] != i + 1){
        for(int j = i + 1; j < n; j++){
          if(v[j] == i + 1) idx = j;
        }
        for(int j = 0; j < (idx-i+1)/2; j++){
          temp = v[i+j];
          v[i+j] = v[idx-j];
          v[idx-j] = temp;
        }
        break;
      }
    }
    for(int i = 0; i < n; i++){
      cout << v[i] << " ";
    }
    cout << '\n';
  }
}
