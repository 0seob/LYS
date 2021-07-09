#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  int T;
  char str[81] = {};
  scanf("%d", &T);
  for(int i = 0; i < T; i++){
    int num;
    scanf("%d %s", &num, str);
    for(int j = 0; j < strlen(str); j++){
      if(j != num-1){
        printf("%c", str[j]);
      }
    }
    printf("\n");
  }
  return 0;
}
