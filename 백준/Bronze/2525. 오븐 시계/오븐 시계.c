#include <stdio.h>

int main(int argc, char const *argv[]) {
  int A,B,C;
  scanf("%d %d",&A,&B);
  scanf("%d",&C);
  A = A + C/60;
  C = C % 60;
  B = B + C;
  if(B > 59){
    B -= 60;
    A += 1;
  }
  if(A > 23){
    A -= 24;
  }
  printf("%d %d\n",A,B);
  return 0;
}
