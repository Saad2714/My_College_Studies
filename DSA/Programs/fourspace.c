#include<stdio.h>
void merge(int arr[], int l, int m, int r){
	int n = r - l + 1;
	int temp_arr[n];	
	int i = l, j = m + 1, k = 0;
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
	int A[] = {2, 1, 3, 7}, n = sizeof(A) / sizeof(A[0]), B[(n * (n - 1)) / 2], k = 0, found = 0;
	printf("Given sequence is...\n");
	for(int i = 0; i < n; i++)
		printf("%d\t", A[i]);
	printf("\n");		
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			B[k++] = A[i] + A[j];		
	mergesort(B, 0, ((n * (n - 1)) / 2) - 1);
	for(int i = 0; i < ((n * (n - 1)) / 2) - 1; i++)
		if(B[i] == B[i + 1]){
			found = 1;
			break;
		}
	if(found)
		printf("We have found two pairs whose respective sums are equal!\n");
	else  
		printf("We didn't find two pairs whose respective sums are equal!\n");						 
	return 0;
}
