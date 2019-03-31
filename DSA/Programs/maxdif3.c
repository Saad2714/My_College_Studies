#include<stdio.h>
int main(){
	int arr[] = {2, 5, 1, 8, 6, 3, 9, 7, 0, 4}, n = sizeof(arr) / sizeof(arr[0]), l = 4, max_dif = arr[l + 1] - arr[0], i;
	printf("Given sequence is...\n");
	for(int i = 0; i < n; i++)
		printf("%d\t", arr[i]);
	printf("\n");
	printf("l is %d...\n", l);
	for(int j = l + 1; j < n; j++){
		if(arr[j] - arr[i] > max_dif)
			max_dif = arr[j] - arr[i];
		if(arr[j - l] < arr[i])
			i = j - l;
	}
	printf("Maximum difference in the given sequence, such that j > i + l, is %d!\n", max_dif); 
	return 0;
}
