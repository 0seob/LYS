#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {

  int N, A, B, C, num, rem;
  long long sum = 0; //자료형을 꼭 확인하자
  vector<int> v;

  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> A;
    v.push_back(A);
  }
  cin >> B >> C;

  for(int i = 0; i < N; i++){
    if(v[i] <= B) sum += 1;
    else{
      num = (v[i] - B) / C;
      rem = (v[i] - B) % C;
      if(rem == 0){
        sum = sum + num + 1;
      }
      else{
        sum = sum + num + 2;
      }
    }
  }
  cout << sum;
  return 0;
}
