
#include<stdio.h>
#define MAX 50
 
#define initial 1
#define visited 2
#define finished 3
 
int n;    /*Number of vertices in the graph */
int adj[MAX][MAX];
void create_graph( );
 
int state[MAX];
int time;
int d[MAX];
int f[MAX];
 
void DF_Traversal();
void DFS(int v);
 
int main()
{
	int i;
	create_graph();
	DF_Traversal();
 
	for(i=0; i<n; i++)
		printf("\nVertex %d, Discovery time - %d, Finshing time - %d\n", i, d[i], f[i]);
 
		return 0;
}/*End of main()*/
 
void DF_Traversal()
{
	int v;
 
	for(v=0; v<n; v++)
		state[v]=initial;
 
	printf("\nEnter starting vertex for Depth First Search : ");
	scanf("%d",&v);
	DFS(v);
	for(v=0; v<n; v++)
	{
		if(state[v] == initial)
			DFS(v);
	}
	printf("\n");
}/*End of DF_Traversal( )*/
 
void DFS(int v)
{
	int i;
	time++;
 
	d[v] = time;	/*discovery time*/
	state[v] = visited;
	printf("%d ", v);
	for(i=0; i<n; i++)
	{
		if(adj[v][i]==1)
		{
			if(state[i]==initial)
				DFS(i);
		}
	}
	state[v] = finished;
	f[v] = ++time;  /*Finishing time*/
}/*End of DFS()*/
 
 
void create_graph()
{
	int i,max_edges,origin,destin;
 
	printf("\nEnter number of vertices : ");
	scanf("%d",&n);
	max_edges=n*(n-1);
 
	for(i=1;i<=max_edges;i++)
	{
		printf("\nEnter edge %d( -1 -1 to quit ) : ",i);
		scanf("%d %d",&origin,&destin);
 
		if( (origin == -1) && (destin == -1) )
			break;
 
		if( origin>=n || destin>=n || origin<0 || destin<0)
		{
			printf("\nInvalid edge!\n");
			i--;
		}
		else
		{
			adj[origin][destin] = 1;
		}
	}
}
