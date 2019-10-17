#include<stdio.h>
#include<stdlib.h>


int n,a[10][10];
int visited[10];
int parent[10];
int discovery[10], finish[10];
int time;

int dfs_visit(int v)
{
	visited[v] = 1;
	discovery[v] = time++;
	
	for(int i=0;i<n;i++)
	{
		if(a[i][v] == 1)
		{
			if(visited[i] == 0)
			{
				parent[i] = v;
				dfs_visit(i);
			}
		}
	}

	visited[v] = 2;
	finish[v] = time++;

}

int dfs(int v)
{
	for(int i=0;i<n;i++)
	{
		visited[i] = 0;
	}

	time =1;
	for(int i=0;i<n;i++)
	{
		if(visited[i] == 0)
		{
			parent[i] = i;
			dfs_visit(i);
		}
	}
}



int main()
{
    int i,j,v;
    printf("Enter the no. of nodes in the graph\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix \n");

    for(i=0;i<n;i++)

    {

        for(j=0;j<n;j++)

        {

            scanf("%d",&a[i][j]);

        }
    }
    printf("Enter the starting node for Depth First search\n");
    scanf("%d",&v);


    dfs(v);

    for(int i=0;i<n;i++)
    {
        printf("%d ~~~ %d : %d \n ",discovery[i],finish[i],i);
    }
}
