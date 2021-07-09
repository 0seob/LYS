#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  long long t, x, y, a, b, sub, cnt;
  scanf("%lld", &t);
  for(int i = 0; i < t; i++){
    scanf("%lld %lld", &a, &b);
    if(a > b){
      x = a;
      y = b;
    }else if(a < b){
      x = b;
      y = a;
    }else{
      printf("0 0\n");
      continue;
    }
    if(x == 0) {
      printf("%lld 0\n", y);
      continue;
    }
    if(y == 0) {
      printf("%lld 0\n", x);
      continue;
    }
    sub = x - y;
    if((y % sub) > sub - (y % sub))
      cnt = sub - (y % sub);
    else cnt = y % sub;
    printf("%lld ll%d\n", sub, cnt);
  }

  return 0;
}
