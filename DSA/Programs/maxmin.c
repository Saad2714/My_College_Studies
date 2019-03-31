#include<stdio.h>
int main(){
	int arr[] = {2, 5, 4, 8, 6, 1, 3, 0, 7, 9}, n = sizeof(arr) / sizeof(arr[0]);
	printf("Given sequence is...\n");
	for(int i = 0; i < n; i++)
		printf("%d\t", arr[i]);
	printf("\n");
	int max_idx = 0, min_idx = 0; 	
	for(int i = 0; i < n - 1; i++)
		if(arr[i + 1] > arr[i]){
			if(arr[i + 1] > arr[max_idx])
				max_idx = i + 1;
			if(arr[i] < arr[min_idx])
				min_idx = i;
		}else{
			if(arr[i] > arr[max_idx])
				max_idx = i;
			if(arr[i + 1] < arr[min_idx])
				min_idx = i + 1;
		}
	printf("Maximum and minimum of the given sequence is %d and %d respectively!\n", arr[max_idx], arr[min_idx]); 
	return 0;
}
