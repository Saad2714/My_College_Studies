#include<stdio.h>
int moving_window(int *a,int i,int j,int k)
{
	int l=0,r=0;
	int s=1;
	int b[5];
	b[0]=0;
	int max=0;
	int t=b[0];
	while(s<j-i+1)
	{
		while(a[b[r]]>=a[s] && r>=0)
		{
			if(abs(a[s]-a[b[r]]>max)
				max = abs(a[s]-a[b[r]])
			r--;
		}
		b[++r]=s;
		if(s-b[l]+1>k)
		{
			l++;
			t=b[l];
		}
		if(abs(a[s]-a[t])>max)
			max=abs(a[s]-a[t]);
		s++;
	}
	return max;
}
