#include <bits/stdc++.h>
#include <list>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  ll t, n, in;
  cin >> t;
  while(t--){
    ll od = 0, ev = 0, stop = 0;
    stack<ll> odd, even;
    cin >> n;
    for(int i = 0; i < n; i++){
      cin >> in;
      if(stop == 1) continue;
      if(in % 2 == 0){
        if(even.size() != 0) ev = even.top();
        if(in < ev){
          cout << "No\n";
          stop = 1;
          continue;
        }
        even.push(in);
      }
      else{
        if(odd.size() != 0) od = odd.top();
        if(in < od){
          cout << "No\n";
          stop = 1;
          continue;
        }
        odd.push(in);
      }
    }
    if(stop != 1) cout << "Yes\n";
  }
}
