#include<stdio.h>
int binarysearch(int arr[], int l, int r, int x){
	int m;	
	while(l <= r){
		m = (l + r) / 2;
		if(x == arr[m])
			return m;
		else if(arr[l] <= arr[m])
			if(x >= arr[l] && x <= arr[m])
				return binarysearch(arr, l, m - 1, x);
			else 
				return binarysearch(arr, m + 1, r, x);	
		else 
			if(x >= arr[m] && x <= arr[r])
				return binarysearch(arr, m + 1, r, x);
			else 
				return binarysearch(arr, l, m - 1, x);
	}	
	return -1;
}
int main(){
	int arr[] = {50, 60, 70, 80, 90, 10, 20, 30, 40};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Given sequence is...\n");
	for(int i = 0; i < n; i++)
		printf("%d\t", arr[i]);
	printf("\n");	
	int x;
	printf("Enter x : ");
	scanf("%d", &x);
	int result = binarysearch(arr, 0, n-1, x);
	if (result == -1)
		printf("x not found!\n");
	else 
		printf("x found at index %d!\n", result);			
	return 0;
}
