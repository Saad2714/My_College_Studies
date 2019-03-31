#include<stdio.h>
void bubblesort(int arr[], int n){
	for(int i = 0; i < n - 1; i++)
		for(int j = 0; j < n - 1 - i; j++)
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}
int main(){
	int arr[] = {10, 50, 30, 90, 80, 20, 40, 70, 60};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Before sorting, array is...\n");
	for(int i = 0; i < n; i++)
		printf("%d\t", arr[i]);
	printf("\n");	
	bubblesort(arr, n);
	printf("After sorting, array is...\n");	
	for(int i = 0; i < n; i++)
		printf("%d\t", arr[i]);
	printf("\n");
	return 0;
}
