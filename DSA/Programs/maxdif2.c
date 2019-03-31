#include<stdio.h>
int main(){
	int arr[] = {2, 5, 4, 8, 6, 1, 3, 9, 7, 0}, n = sizeof(arr) / sizeof(arr[0]), max_dif = arr[1] - arr[0], i;
	printf("Given sequence is...\n");
	for(int i = 0; i < n; i++)
		printf("%d\t", arr[i]);
	printf("\n");
	for(int j = 1; j < n; j++){
		if(arr[j] - arr[i] > max_dif)
			max_dif = arr[j] - arr[i];
		if(arr[j] < arr[i])
			i = j;
	}
	printf("Maximum difference in the given sequence, such that j > i, is %d!\n", max_dif); 
	return 0;
}
