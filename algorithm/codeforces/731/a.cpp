#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int t, xa, ya, xb, yb, xf, yf;
  scanf("%d", &t);
  for(int i = 0; i < t; i++){
    printf("\n");
    scanf("%d %d", &xa, &ya);
    scanf("%d %d", &xb, &yb);
    scanf("%d %d", &xf, &yf);

    int len = abs(xb - xa) + abs(yb - ya);
    if(xa == xb && xb == xf){
      if((ya < yf && yf < yb) || (ya > yf && yf > yb)) len += 2;
    }
    else if(ya == yb && yb == yf){
      if((xa < xf && xf < xb) || (xa > xf && xf > xb)) len += 2;
    }
    printf("%d\n", len);
  }

  return 0;
}
