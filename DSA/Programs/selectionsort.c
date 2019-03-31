#include<stdio.h>
void selectionsort(int arr[], int n){
	int min_idx;
	for(int i = 0; i < n - 1; i++){
		min_idx = i;
		for(int j = i + 1; j < n; j++)
			if(arr[j] < arr[min_idx])
				min_idx = j;
		int temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
	}
}
int main(){
	int arr[] = {10, 50, 30, 90, 80, 20, 40, 70, 60};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Before sorting, array is...\n");
	for(int i = 0; i < n; i++)
		printf("%d\t", arr[i]);
	printf("\n");	
	selectionsort(arr, n);
	printf("After sorting, array is...\n");	
	for(int i = 0; i < n; i++)
		printf("%d\t", arr[i]);
	printf("\n");
	return 0;
}
