#include<stdio.h>
int fib(int n){
	int a = 0, b = 1, c, i; 
	if( n == 0) 
		return a; 
  	for (i = 2; i <= n; i++){ 
     		c = a + b; 
     		a = b; 
     		b = c; 
  	} 
  	return b; 
}
int main(){
	int n = 6;
	printf("...term %d in fibonacci sequence is %d\n", n, fib(n)); 
	return 0;
}
