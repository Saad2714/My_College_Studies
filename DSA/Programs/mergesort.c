#include<stdio.h>
#include"mergesort.h"
void mergesort(int *a,int i,int j)
{
	if(i<j)
	{
		int m=(i+j)/2;
		mergesort(a,i,m);
		mergesort(a,m+1,j);
		merge(a,i,j,m);
	}
}
void merge(int *a,int i,int j,int m)
{
	int l=i;
	int r=m+1;
	int p=0;
	int b[j];
	while(l<=m && r<=j)
	{
		if(a[l]<a[r])
			b[p++]=a[l++];
		else 
			b[p++]=a[r++];
	}
	while(l<=m)
		b[p++]=a[l++];
	while(r<=j)
		b[p++]=a[r++];
	l=i;
	p=0;
	while(l<=j)
		a[l++]=b[p++];
}
