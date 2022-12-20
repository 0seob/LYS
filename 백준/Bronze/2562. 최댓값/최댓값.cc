#include <stdio.h>

int main(int argc, char *argv[]) {
	int arr[9] = {}, max = 0, idx, i;
	for(i = 0; i < 9; i++){
		scanf("%d", &arr[i]);
		if(max < arr[i]){
			max = arr[i];
			idx = i + 1;
		}
	}
	printf("%d\n%d", max, idx);
} 
