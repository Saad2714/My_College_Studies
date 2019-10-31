#include<stdio.h>
#include"fib.h"
int fib(int n)
{
	int f[2][2]={{1,1},{1,0}};
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	power(f,n-1);
	return f[0][0]*1+f[0][1]*0;
}
void power(int f[2][2],int n)
{	
	int temp[2][2];
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			temp[i][j]=f[i][j];	
	if(n==1){
		return;
	}
	if(n%2==0) 
	{
		power(f,n/2);
		multiply(f,f);
		return;
	}
	power(f,n-1);
	multiply(f,temp);

}
void multiply(int f[2][2],int m[2][2])
{
	int x,y,z,w;
	x=f[0][0]*m[0][0]+f[0][1]*m[1][0];
	y=f[0][0]*m[0][1] + f[0][1]*m[1][1];
	z=f[1][0]*m[0][0] + f[1][1]*m[1][0];
	w=f[1][0]*m[0][1] + f[1][1]*m[1][1];
	f[0][0]=x;
	f[0][1]=y;
	f[1][0]=z;
	f[1][1]=w;
}
