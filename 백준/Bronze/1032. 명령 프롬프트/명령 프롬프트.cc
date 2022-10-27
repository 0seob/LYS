#include <bits/stdc++.h>
#include <map>
#include <list>
#include <tuple>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
#define X first
#define Y second
typedef long long ll;

using namespace std;

int board[305][305];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(int argc, char const *argv[]) {
  FASTIO();
  int N;
  cin >> N;
  vector<string> v;
  for(int i = 0; i < N; i++){
    string temp;
    cin >> temp;
    v.push_back(temp);
  }
  string str = "";
  for(int i = 0; i < v[0].size(); i++){
    int dif = 0;
    for(int j = 1; j < v.size(); j++){
      if(dif == 1) continue;
      if(v[0][i] != v[j][i]){
        str += "?";
        dif = 1;
      }
    }
    if(dif == 0) str += v[0][i];
  }
  cout << str;
}