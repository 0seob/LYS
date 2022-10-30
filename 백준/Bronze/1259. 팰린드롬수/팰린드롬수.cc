#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int num, num1, size, a, b, c, d, e;
  while(1){
    scanf("%d",&num);
    num1 = num;
    a = num/10000;
    b = num/1000 - a*10;
    c = num/100 - a*100 - b*10;
    d = num/10 - a*1000 - b*100 - c*10;
    e = num - a*10000 - b*1000 - c*100 - d*10;
    size = 0;
    while(num != 0){
        num /= 10;
        size++;
    }
    if(num1 == 0) break;
    else{
      if(size == 1) printf("yes\n");
      else if(size == 2 && d == e) printf("yes\n");
      else if(size == 3 && c == e) printf("yes\n");
      else if(size == 4 && b == e && c == d) printf("yes\n");
      else if(size == 5 && a == e && b == d) printf("yes\n");
      else printf("no\n");
    }
  }
  return 0;
}
