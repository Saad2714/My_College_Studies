#include<stdio.h>
void swap(int *a,int *b)
{
	int c=*a;
	*a=*b;
	*b=c;
}

int partition(int *a,int i,int j)
{
        int p=a[i];
        int l=i+1;
        int r=j;
        while(l<=r)
        {
                while(l<=r && a[l]<=p)
                        l++;
                while(l<=r && a[r]>p)
                        r--;
                if(l<=r)
                {
                        swap(&a[l],&a[r]);
                        l++,r--;
                }
        }
        swap(&a[r],&a[i]);
        return r;
}

int findrank(int *a,int i,int j,int r)
{
	if(i<=j)    
	{
		int p=i+rand()%(j-i+1);
		swap(&a[i],&a[p]);
		int k=partition(a,i,j);
		if(r==j-k+1)
			return a[k];
		else if(r<j-k+1)
			return findrank(a,k+1,j,r);
		else
			return findrank(a,i,k-1,r-j+k-1);	
	}
}
