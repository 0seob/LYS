#include <stdio.h>

int arr[2200][2200]={};

void star(int x, int y, int size){
  if(size == 1){
      arr[x][y] = 1;
  }
  else {
      size /= 3;
      star(x, y, size);
      star(x, y + size, size);
      star(x, y + size*2, size);

      star(x + size, y, size);
      //size(x + size, y + size, size);
      star(x + size, y + size*2, size);

      star(x + size*2, y, size);
      star(x + size*2, y + size, size);
      star(x + size*2, y + size*2, size);
  }
}

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d",&n);
  star(0, 0, n);
  for(int i = 0; i < n; i++){
    for(int j=0;j<n;j++){
      if(arr[i][j]==1){
        printf("*");
      }
      else printf(" ");
    }
    printf("\n");
  }
  return 0;
}
