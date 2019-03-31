#include<stdio.h>
int main(){
	int arr[] = {2, -1, 5, -9, 4, 3, 0, -6, -7, -8}, n = sizeof(arr) / sizeof(arr[0]), max_pre_dif = arr[0], sum = 0;
	printf("Given sequence is...\n");
	for(int i = 0; i < n; i++)
		printf("%d\t", arr[i]);
	printf("\n");
	for(int j = 0; j < n; j++){
		sum = sum + arr[j]; 
		if(sum > max_pre_dif)
			max_pre_dif = sum;
		if(sum < 0)
			sum = 0;
	}
	printf("Maximum prefix difference in the given sequence, such that j > i, is %d!\n", max_pre_dif); 
	return 0;
}
