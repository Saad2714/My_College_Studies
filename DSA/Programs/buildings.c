#include<stdio.h>
int findbuilding(int arr[], int low, int high){
	if(arr[0] > arr[1])
		return 0;
	if(arr[high] > arr[high - 1])
		return high;
	int mid = (low + high) / 2;
	if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
		return mid;
	if(arr[mid + 1] > arr[mid - 1])
		return findbuilding(arr, mid + 1, high);
	else
		return findbuilding(arr, low, mid - 1);
	return 0;
}
int main(){
	int arr[] = {2, 3, 2, 1, 4, 3}, n = sizeof(arr)/sizeof(arr[0]);
	printf("Given sequence is...\n");
	for(int i = 0; i < n; i++)
		printf("%d\t", arr[i]);
	printf("\n");	
	printf("We have found a building with adjacent buildings being shorter than it at index %d!\n", findbuilding(arr, 0, n - 1));
	return 0;
}
