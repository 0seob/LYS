#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  long long K, N, X;
  scanf("%d %d", &K, &N);
  if(N == 1){
    printf("-1\n");
    return 0;
  }
  else{
    if((N*K)%(N-1) == 0){
      X = (N*K)/(N-1);
    }
    else{
      X = (N*K)/(N-1) + 1;
    }
  }
  printf("%d", X);
}
