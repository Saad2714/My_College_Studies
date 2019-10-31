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
int *klargest(int *a,int i,int j,int k)
{
	int *b=(int*)malloc(2*k*sizeof(int));
	for(int p=0;p<2*k && p<=j;p++)
	{
		b[p]=a[p];
	}
	if(2*k>j)
	{
		findrank(b,i,j,k);
	}
	else
	{
		int s=0;
		for(int p=2*k;s+(p-2*k)<=j;p+=k)
		{
			findrank(b,i,2*k-1,k);
			for(s=0;s<k && (s+p)<=j;s++)
			{
				b[s]=a[s+p];
			}
		}
	}
	int *c=(int*)malloc(k*sizeof(int));
	if(2*k<=j)
	{
		for(int p=0;p<k;p++)
		{	
			c[p]=b[2*k-p-1];
		}
		return c;
	}
	else
        {
                for(int p=0;p<k;p++)
                {
                        c[p]=b[j-p];
                }
                return c;
        }

}

