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
void quicksort(int *a,int i,int j)
{
	if(i<j)
	{
		int k=partition(a,i,j);
		quicksort(a,i,k-1);
		quicksort(a,k+1,j);
	}
}
