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
int fournospace(int A[], int n){
	mergesort(A, 0, n - 1);
	int l, r, x;
	for(int i = 0; i < n ; i++)		
		for(int j = i + 1; j < n ; j++){ 
			x = A[i] + A[j];
			l = 0;
			r = n - 1;
			while(l <= r)
				if(A[l] + A[r] > x)
					r--;
				else if(A[l] + A[r] < x)
					l++;
				else
					if(l != i && r != j)
						return 1;
					else
						break;
		}
	return 0;
}
int main(){
	int A[] = {2, 5, 3, 4}, n = sizeof(A) / sizeof(A[0]);
	printf("Given sequence is...\n");
	for(int i = 0; i < n; i++)
		printf("%d\t", A[i]);
	printf("\n");
	if(fournospace(A, n))
		printf("We have found two pairs whose respective sums are equal!\n");
	else  
		printf("We didn't find two pairs whose respective sums are equal!\n");						 
	return 0;
}
