#include<stdio.h>
void merge(int arr[], int l, int m, int r){
	int n = r - l + 1, temp_arr[n], i = l, j = m + 1, k = 0;
	while(i <= m && j <= r)
		if(arr[i] < arr[j])
			temp_arr[k++] = arr[i++];
		else 
			temp_arr[k++] = arr[j++];
	while(i <= m)
		temp_arr[k++] = arr[i++];
	while(j <= r)
		temp_arr[k++] = arr[j++];	
	for(int i = 0; i < n; i++)
		arr[l + i] = temp_arr[i];		
}
void mergesort(int arr[], int l, int r){
	if (l < r){
		int m = (l + r) / 2;
		mergesort(arr, l, m);
		mergesort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
int main(){
	int arr[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Before sorting, array is...\n");
	for(int i = 0; i < n; i++)
		printf("%d\t", arr[i]);
	printf("\n");	
	mergesort(arr, 0, n - 1);	
	printf("After sorting, array is...\n");	
	for(int i = 0; i < n; i++)
		printf("%d\t", arr[i]);
	printf("\n");
	return 0;
}
