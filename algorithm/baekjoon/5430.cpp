#include <bits/stdc++.h>
#include <list>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

using namespace std;

int main(int argc, char const *argv[]) {
  FASTIO();
  int T;
  cin >> T;
  for(int i = 0; i < T; i++){
    int rev = 1, in, error = 0, j = 0;
    string str, arr, s ="";
    deque<int> de;
    cin >> str;
    cin >> in;
    cin >> arr;
    while(arr[j] != '\0'){
      int x = 0;
      while(arr[j] >= '0' && arr[j] <= '9'){
        x *= 10;
        x += int(arr[j] - '0');
        j++;
      }
      if(x != 0) de.push_back(x);
      j++;
    }
    for(int j = 0; j < str.length(); j++){
      if(str[j] == 'R') rev *= -1;
      else if(str[j] == 'D' && de.size() != 0){
        if(rev == 1) de.pop_front();
        else de.pop_back();
      }
      else{
        error = 1;
        break;
      }
    }
    if(error == 1){
      cout << "error" << '\n';
      continue;
    }
    int size = de.size();
    cout << "[";
    if(rev == 1){
      for(int j = 0; j < size; j++){
        if(j != size - 1) cout << de[j] << ',';
        else cout << de[j];
      }
    }
    else{
      for(int j = size - 1; j >= 0; j--){
        if(j != 0) cout << de[j] << ',';
        else cout << de[j];
      }
    }
    cout << "]" << '\n';
  }
}
