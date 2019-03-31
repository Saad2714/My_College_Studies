#include<stdio.h>
#include<stdlib.h>
int partition(int arr[], int l, int r){
	int pivot = arr[l];
	int i = l + 1, j = r;
	while(i <= j){
		while(i <= j && arr[i] <= pivot)
			i++;
		while(i <= j && arr[j] > pivot)
			j--;
		if(i <= j){
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}	
	}
	int temp = arr[l];
	arr[l] = arr[j];
	arr[j] = temp;
	return j;	
}	
void quicksort(int arr[], int l, int r){
	if(l < r){
		int p = l + rand() % (r - l + 1);
		int temp = arr[l];
		arr[l] = arr[p];
		arr[p] = temp;
		int k = partition(arr, l, r);
		quicksort(arr, l, k - 1);
		quicksort(arr, k + 1, r);
	} 
}
int main(){
	int arr[] = {10, 50, 30, 90, 80, 20, 40, 70, 60};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Before sorting, array is...\n");
	for(int i = 0; i < n; i++)
		printf("%d\t", arr[i]);
	printf("\n");	
	quicksort(arr, 0, n - 1);	
	printf("After sorting, array is...\n");	
	for(int i = 0; i < n; i++)
		printf("%d\t", arr[i]);
	printf("\n");
	return 0;
}
