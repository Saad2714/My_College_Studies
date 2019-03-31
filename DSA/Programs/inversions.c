#include<stdio.h>
int merge(int arr[], int l, int m, int r){
	int n = r - l + 1, temp_arr[n], i = l, j = m + 1, k = 0, inv_count = 0;
	while(i <= m && j <= r)
		if(arr[i] < arr[j])
			temp_arr[k++] = arr[i++];
		else{ 
			temp_arr[k++] = arr[j++];
			inv_count += m + 1 - i;
		}
	while(i <= m)
		temp_arr[k++] = arr[i++];
	while(j <= r)
		temp_arr[k++] = arr[j++];	
	for(int i = 0; i < n; i++)
		arr[l + i] = temp_arr[i];
	return inv_count;		
}
int mergesort(int arr[], int l, int r){
	int m, inv_count = 0;
	if (l < r){
		m = (l + r) / 2;
		inv_count = mergesort(arr, l, m);
		inv_count += mergesort(arr, m + 1, r);
		inv_count += merge(arr, l, m, r);
	}
	return inv_count;
}
int main(){
	int arr[] = {1, 5, 8, 2, 4, 9, 6, 0, 7, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Given sequence is...\n");
	for(int i = 0; i < n; i++)
		printf("%d\t", arr[i]);
	printf("\n");	
	printf("Number of inversions are %d!\n", mergesort(arr, 0, n-1));
	return 0;
}
