#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
int minval(int x, int y)
{
	return (x<y)?x:y;
}
int rmq(int* st, int l, int r, int i, int j, int k)
{
       if(i<=l && j>=r)
	       return st[k];
       if(i>r || l>j)
	       return INT_MAX;
       int mid=(l+r)/2;
       return minval(rmq(st, l, mid, i, j, 2*k+1),rmq(st, mid+1, r, i, j, 2*k+2));
}
void update(int arr[], int* st, int n, int i, int new_val)
{
	arr[i]=new_val;
	int j=n+i-1;
	int l;
	while(j>0)
	{
		int k=(j-1)/2;
		if(arr[st[2*k+1]]<arr[st[2*k+2]])
			l=2*k+1;
		else
			l=2*k+2;
	st[k]=st[l];
	j=k;	
	}
}
int constructst(int arr[], int l, int r, int* st, int k)
{
	if(l==r)
	{
		st[k]=arr[l];
		return arr[l];
	}
	int mid=(l+r)/2;
	st[k]=minval(constructst(arr, l, mid, st, 2*k+1), constructst(arr, mid+1, r, st, 2*k+2));
	return st[k];
}
int *st_initial(int arr[], int n)
{
	int x=(int)(ceil(log2(n)));
	int max_size=2*(int)pow(2,x)-1;
	int *st=(int*)malloc(max_size*4);
	constructst(arr, 0, n-1, st, 0);
	return st;
}
int main()
{
	int arr[]={12, 4, 9, 7, 18, 21, 3, 5};
	int n=sizeof(arr)/sizeof(arr[0]);
	int *st=st_initial(arr, n);
	printf("min value is %d", rmq(st, 0, n-1, 2, 5, 0));
}
