#include<stdio.h>
void insertionsort(int arr[], int n){
	int key, j;
	for(int i = 1; i < n; i++){
		key = arr[i];
		j = i - 1;
		while(j >= 0 && arr[j] > key){
			arr[j + 1] = arr[j];
			j = j - 1;
		}	
		arr[j + 1] = key;
	}
}
int main(){
	int arr[] = {10, 50, 30, 90, 80, 20, 40, 70, 60};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Before sorting, array is...\n");
	for(int i = 0; i < n; i++)
		printf("%d\t", arr[i]);
	printf("\n");	
	insertionsort(arr, n);	
	printf("After sorting, array is...\n");	
	for(int i = 0; i < n; i++)
		printf("%d\t", arr[i]);
	printf("\n");
	return 0;
}
