#include<stdio.h>

int main()
{
	int n;
	int a[n][n],a_transpose[n][n];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			a_transpose[i][j] = a[j][i];
		}
	}
}