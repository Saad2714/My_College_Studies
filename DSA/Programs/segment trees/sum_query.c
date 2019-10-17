#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//function to calculate sum for range query i->j 
int getsum_cal(int *st, int l, int r, int i, int j, int k)//k is index of current node
{
	if(i<=l && j>=r)
		return st[k];
	if(r<i || l>j)
		return 0;
	int mid=(l+r)/2;
	return getsum_cal(st, l, mid, i, j, 2*k+1)+getsum_cal(st, mid+1, r, i, j, 2*k+2);
}
void update_nodes(int* st, int l, int r, int i, int diff, int k)
//diff is the difference in values of the original and updated array value
//i is the index of the element to be updated
{
	if(i<l || i>r)
		return;
	st[k]=st[k]+diff;
	if(l!=r)
	{
		int mid=(l+r)/2;
		update_nodes(st, l ,mid, i, diff, 2*k+1);
		update_nodes(st, mid+1, r, i, diff, 2*k+2);
	}
}
void update(int arr[], int* st, int n, int i, int new_val)//function to update value in arr and st
{
	if(i<0 || i>n-1)
	{
		printf("Invalid Input");
		return;
	}
	int diff=new_val-arr[i];
	arr[i]=new_val;
	update_nodes(st, 0, n-1, i, diff, 0);
}
int getsum(int *st, int n, int i, int j)
{
	if(i<0 || j>n-1 || i>j)
		return -1;
	return getsum_cal(st, 0, n-1, i, j, 0);
}
int constructst(int arr[], int l, int r,int *st, int k)
	//function to create st from arr[l...r]
{
	if(l==r)
	{
		st[k]=arr[l];
		return arr[l];
	}
	int mid=(l+r)/2;
	st[k]=constructst(arr, l, mid, st, 2*k+1)+constructst(arr, mid+1, r, st, 2*k+2);
	return st[k];
}
int *st_initial(int arr[], int n)
{
	int x=(int)(ceil(log2(n)));
	int max_size=2*(int)pow(2,x)-1;
	int *st=(int *)malloc(max_size*4);
	constructst(arr, 0, n-1, st, 0);
	return st;
}
int main()
{
	int arr[]={1,3,5};
	int n=sizeof(arr)/sizeof(arr[0]);
	int *st=st_initial(arr,n);
	printf("sum is: %d",getsum(st, n, 0, 2));
	update(arr, st, n, 1, 10);	
	printf("sum is: %d",getsum(st, n, 0, 2));
}
