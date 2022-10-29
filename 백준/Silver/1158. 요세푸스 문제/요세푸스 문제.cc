#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int N, K, cnt = 1, num = 1;
  vector<int> v;
  vector<int> v2;

  scanf("%d %d",&N, &K);

  for(int i = 1; i <= N; i++){
    v.push_back(i);
  }

  int left = N;

  while(left != 0){
    if(num <= N){
      if(v[num-1] != 0){
        if(cnt == K){
          v2.push_back(num);
          v[num-1] = 0;
          num++;
          cnt = 1;
          left -= 1;
        }
        else{
          cnt++;
          num++;
        }
      }
      else{
        num++;
      }
    }
    else{
      num -= N;
    }
  }

  printf("<");
  for(int i = 0; i < N-1; i++){
    printf("%d, ",v2[i]);
  }
  printf("%d", v2[N-1]);
  printf(">");

  return 0;
}
