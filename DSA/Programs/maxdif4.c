#include<stdio.h>
int main(){
	int A[] = {2, 5, 1, 8, 6, 3, 9, 7, 0, 4}, n = sizeof(A) / sizeof(A[0]), k = 4, max_dif = A[1] - A[0], l, r, B[n], j = 1;
	printf("Given sequence is...\n");
	for(int i = 0; i < n; i++)
		printf("%d\t", A[i]);
	printf("\n");
	printf("k is %d...\n", k);
	while(j < n){
		while(r >= 0 && A[B[r]] >= A[j])
			r--;
		B[++r] = j;
		if(j - B[l] > k)
			l++;
		if(A[j] - A[B[l]] > max_dif)
			max_dif = A[j] - A[B[l]];
		j++; 
	}
	printf("Maximum difference in the given sequence, such that i <= j + k, is %d!\n", max_dif); 
	return 0;
}
