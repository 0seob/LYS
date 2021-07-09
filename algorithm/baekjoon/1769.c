#include <stdio.h>
#include <string.h>

int arrayToInt(char* X, int len){
  int ret = 0;
  for(int i = 0; i < len; i++){
    ret += (X[i] - '0');
  }
  return ret;
}

void intToArray(char* X, int n){
  int i = 0;
  while(n > 0){
    X[i++] = (n % 10) + '0';
    n /= 10;
  }
  X[i] = '\0';
}

int main(int argc, char const *argv[]) {
  char X[1000001] = {};
  int count = 0, ans = 0;
  scanf("%s", X);
  int Xlen = strlen(X);
  if(Xlen == 1) ans = X[0] - '0';
  else {
    ans = arrayToInt(X, Xlen);
    intToArray(X, ans);
    count++;
  }
  while(ans >= 10){
    Xlen = strlen(X);
    ans = arrayToInt(X, Xlen);
    intToArray(X, ans);
    count++;
  }
  printf("%d\n", count);
  if(ans == 3 || ans == 6 || ans == 9)  printf("YES\n");
  else printf("NO\n");
  return 0;
}
