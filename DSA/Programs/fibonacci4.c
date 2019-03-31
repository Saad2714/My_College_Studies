#include<stdio.h>
#include<stdlib.h>
int mmulti(int A[2][2], int B[2][2]){
	int w, x, y, z;
	w = A[0][0] * B[0][0] + A[0][1] * B[1][0];	
	x = A[0][0] * B[0][1] + A[0][1] * B[1][1];
	y = A[1][0] * B[0][0] + A[1][1] * B[1][0];
	z = A[1][0] * B[0][1] + A[1][1] * B[1][1];
	A[0][0] = w;
	A[0][1] = x;
	A[1][0] = y;
	A[1][1] = z;
}
int power(int A[2][2], int N){	
	int I[2][2] = {{1, 0}, {0, 1}};
	while(N > 0){
		if(N % 2 != 0)
			mmulti(I, A);
		mmulti(A, A);
		N = N / 2;
	}
	return I[0][0];
} 
int fib(int n){
	if (n == 0)
		return n;
	int matrix[2][2] = {{1, 1}, {1, 0}};
	return power(matrix, n - 1);
}
int main(){
	int n = 12;
	printf("...term %d in fibonacci sequence is %d\n", n, fib(n)); 
	return 0;
}
