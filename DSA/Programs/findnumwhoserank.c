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
int findnumwhoserank(int A[], int i, int j, int r){
	if(i <= j){
		int p = i + rand() % (j - i + 1);
		int temp = A[p];
		A[p] = A[i];
		A[i] = temp;
		int k = partition(A, i, j);
		if(r == j - k + 1) 
			return A[k];
		else if(r < j - k + 1)
			findnumwhoserank(A, k + 1, j, r);
		else
			findnumwhoserank(A, i, k, r - j + k);					  
	}
}
int main(){
	int A[] = {21, 65, 43, 28, 16, 11, 32, 80, 72, 57}, n = sizeof(A) / sizeof(A[0]);
	printf("Given sequence is...\n");
	for(int i = 0; i < n; i++)
		printf("%d\t", A[i]);
	printf("\n");	
	int r;
	printf("Enter rank : ");
	scanf("%d", &r);
	printf("%d has rank %d!\n", findnumwhoserank(A, 0, n - 1, r), r);
	return 0;
}
