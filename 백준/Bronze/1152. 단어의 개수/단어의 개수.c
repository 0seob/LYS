#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char ch[1000001];
  scanf("%[^\n]s",ch);
  int len = strlen(ch),num=1;
  for(int i=0;i<len;i++){
    if(ch[i] == ' ') num++;
  }
  if(ch[len-1] == ' ') num -= 1;
  if(ch[0] == ' ') num -= 1;
  printf("%d\n",num);
  return 0;
}
