#include<stdio.h>
int merge(int *a,int i,int j,int m)
{
        int l=i;
        int r=m+1;
        int p=0;
        int b[j];
	int count=0;
        while(l<=m && r<=j)
        {
		if(a[l]>a[r])
			count+=m-l+1;
                if(a[l]<a[r])
                        b[p++]=a[l++];
                else
		{
                        b[p++]=a[r++];
		}
        }
        while(l<=m)
                b[p++]=a[l++];
        while(r<=j)
                b[p++]=a[r++];
        l=i;
        p=0;
        while(l<=j)
                a[l++]=b[p++];
	return count;
}
int inversion_pair(int *a,int i,int j)
{
	if(i<j)
	{
		int mid=(i+j)/2;
		return inversion_pair(a,i,mid)+inversion_pair(a,mid+1,j) + merge(a,i,j,mid);
	}
	else
	{
		return 0;
	}
}	
