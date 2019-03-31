#include<stdio.h>
int linearsearch(int arr[], int n, int x){
	for(int i = 0; i < n; i++)
		if(arr[i] == x)
			return i;
	return -1;
}
int main(){
	int arr[] = {10, 50, 30, 90, 80, 20, 40, 70, 60};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 10;
	int result = linearsearch(arr, n, x);
	if (result == -1)
		printf("Number not found!\n");
	else 
		printf("Number found at index %d!\n", result);			
	return 0;
}
