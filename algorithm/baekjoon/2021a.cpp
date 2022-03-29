#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int H, W, N, M;
  scanf("%d %d %d %d", &H, &W, &N, &M);
  int row = (W+1) / (M+1);
  int col = (H+1) / (N+1);
  printf("%d", row*col);
}
