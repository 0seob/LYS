#include <stdio.h>

int main(){
  int a,b,c,d,sum;
  for(int i=0;i<3;i++){
    scanf("%d %d %d %d",&a,&b,&c,&d);
    sum = a+b+c+d;
    if(sum==0){
      printf("%s\n","D");
    }
    else if(sum==3){
      printf("%s\n","A");
    }
    else if(sum==2){
      printf("%s\n","B");
    }
    else if(sum==1){
      printf("%s\n","C");
    }
    else if(sum==4){
      printf("%s\n","E");
    sum=0;
    }
  }
}
