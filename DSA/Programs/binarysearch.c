#include<stdio.h>
int binarysearch(int arr[], int l, int r, int x){
	int m;	
	while(l <= r){
		m = (l + r) / 2;
		if(x == arr[m])
			return m;
		else if(x > arr[m])
			l = m + 1;	
		else 
			r = m - 1;  
	}	
	return -1;
}
int main(){
	int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 60;
	int result = binarysearch(arr, 0, n-1, x);
	if (result == -1)
		printf("Number not found!\n");
	else 
		printf("Number found at index %d!\n", result);			
	return 0;
}
