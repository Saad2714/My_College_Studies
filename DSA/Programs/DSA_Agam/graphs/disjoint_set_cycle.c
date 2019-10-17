#include<stdio.h>
#include<limits.h>

int parent(int set[], int a)
{
	if(set[a] < -1)
		return a;
	else
		parent(set,set[a]);
}
int union_2( int set[], int a, int b)
{
	if(set[a] == set[b] && a == b)
		return -1;
	if(set[a] <=-1 && set[b] <=-1)
	{
		if(set[a] > set[b])
		{
			set[b] += set[a];
			set[a] = b;
			return 0;
		}
		else
		{
			set[a] += set[b];
			set[b] = a;
			return 0;
		}
	}
	else if(set[a] <-1 && set[b] >-1)
	{
		union_2(set,a,set[b]);
	}
	else if(set[a] >-1 && set[b] <-1)
	{
		union_2(set,set[a],b);
	}
	else
	{
		union_2(set,set[a],set[b]);
	}
}
//pass edge list
void cycle(int a[][2], int n)
{
	int vertex[n], disjoint[n];
	for(int i=0;i<n;i++)
	{
		vertex[i] = 0; // 0 implies not yet considered for set
		disjoint[i] = -1; //initially, each vertex is a set in intself
	}

	int k=0;
	while(a[k][0] != -1 && a[k][1] != -1)
	{
		if(vertex[a[k][0]] == 0)
		{
			disjoint[a[k][0]] = -2;
			disjoint[a[k][1]] = a[k][0];
			vertex[a[k][0]] = 1;
			vertex[a[k][1]] = 1;
			a[k][0] = INT_MIN;
			a[k][1] = INT_MIN;
		}
		k++;
	}
	k=0;
	int bool =0;
	while(a[k][0] != -1 && a[k][1] != -1)
	{
		if(a[k][0] != INT_MIN && a[k][1] != INT_MIN)
		{
			int ans = union_2(disjoint,a[k][0],a[k][1]);
			if(ans == -1)
			{
				printf("Cycle exists\n");
				bool = 1;
				break;
			}
		}
		k++;
	}

	if(bool == 0)
		printf("No cycle\n");

	for(int i=0;i<n;i++)
	{
		if(disjoint[i] > -1)
			disjoint[i] = parent(disjoint,i);
	}


}


int main()
{
	int n;
	printf("Numbber of vertices: ");
	scanf("%d",&n);

	printf("Enter edge list. -1 -1 to exit\n");
	int a[n*n][2];
	// instead of this maintain a n*n matrix and ask user to just give the edge list as input
	// put that in the matrix.
	int i=0;
	while(1)
	{
		scanf("%d %d", &a[i][0],&a[i][1]);
		
		if(a[i][0] == -1 && a[i][1] == -1)
			break;
		else
			i++;
	}

	cycle(a,n);
}
