#include<stdio.h>
int findk(int arr[], int low, int high){
	if(low == high)
		return low;
	if(high == low + 1 && arr[low] >= arr[high])
		return low;
	if(high == low + 1 && arr[low] < arr[high])
		return high;
	int mid = (low + high) / 2;
	if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
		return mid;
	if(arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1])
		return findk(arr, low, mid - 1);
	else
		return findk(arr, mid + 1, high);
}
int main(){
	int arr[] = {2, 7, 19, 23, 56, 8, 3, 2, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("\'k\' in given increasing-decreasing sequence is %d\n", findk(arr, 0, n - 1) + 1);
	return 0;
}
