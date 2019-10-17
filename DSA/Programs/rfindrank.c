#include<stdio.h>
int rfindrank(int A[], int, int, int);
int partition(int A[], int, int);
int main()
{
	int A[6]={3,1,5,6,2,4};
	printf("%d\n",rfindrank(A,0,5,3));
	for(int i=0;i<6;i++)
		printf("%d \n", A[i]);
}
int rfindrank(int A[], int i, int j, int r)
{
	int k=partition(A, i, j);
	if(r==j-k+1)
		return A[k];
	else if(r<j-k+1)
		return rfindrank(A, k+1, j, r);
	else
		return rfindrank(A, i, k, j-i+k);

}
int partition(int A[], int l, int r)
{
	int p=A[r];
	int i=l-1;
	int t;
	for(int j=l;j<r;j++)
	{
		if(A[j]<p)
		{
			i++;
			t=A[i];
			A[i]=A[j];
			A[j]=t;
		}
	}
	t=A[i+1];
	A[i+1]=A[r];
	A[r]=t;
	return i+1;

}
