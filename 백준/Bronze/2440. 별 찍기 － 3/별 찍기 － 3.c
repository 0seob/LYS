#include <stdio.h>

int main(void) {
	int t;
	scanf("%d",&t);
	for(int j=0;j<t;j++){
		for(int i=j;i<t;i++){
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}