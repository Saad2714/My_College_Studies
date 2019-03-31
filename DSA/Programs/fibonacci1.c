#include<stdio.h>
int fib(int n){
	if(n == 0 || n == 1)
		return n;
	else
		return fib(n-1) + fib(n-2);
}
int main(){
	int n = 0;
	printf("...term %d in fibonacci sequence is %d\n", n, fib(n)); 
	return 0;
}
