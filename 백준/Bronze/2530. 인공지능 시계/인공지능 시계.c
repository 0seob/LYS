#include <stdio.h>

int main(int argc, char const *argv[]) {
  int A,B,C,D;
  scanf("%d %d %d",&A,&B,&C);
  scanf("%d",&D);
  A = A + D/3600;
  D = D % 3600;
  B = B + D/60;
  D = D % 60;
  C = C + D;
  if(C>59){
    B += 1;
    C -= 60;
  }
  if(B>59){
    A += 1;
    B -= 60;
  }
  if(A>23) A = A % 24;
  printf("%d %d %d",A,B,C);
  return 0;
}
