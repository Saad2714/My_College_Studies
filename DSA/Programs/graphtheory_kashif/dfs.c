#include<stdio.h>
#include<stdlib.h> 
void DFS(int);
int G[10][10], visited[10],n; //n is number of vertices and the graph is sorted in a array G[10][10]
int W[10];
int P[10];
int Conn[10][10];
void main()
{
    int i,j;
    printf("Enter number of vertices :");
   
	scanf("%d",&n);
 
   
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			//printf("G[%d][%d]\n",i,j);
			G[i][j]=0;
		}

	}
	int a,b;
	G[0][1]=1;
	P[1]=0;
	W[0]=13;
	W[1]=24;
	int p=433;
	for(j=2;j<n;j++)
	{
		P[j]=rand()%j;		
		//G[][b-1]=1;
		//	G[b-1][a-1]=1;
		W[j]=250-(rand()%p);
	}

	
 for(int k=1;k<n;k++)
	 printf("%d %d\n",P[k],k);
   for(i=0; i<n; i++)
        visited[i]=0;
 
}
int t=0; 
c=0;
void pairs(int i,int t,int a,int b)
{
    int j;
    visited[i]=1;
    
	
	for(j=0; j<n; j++)
	{
		if(!visited[j])
		{
			pairs(j,t)
			//for(int l=0;l<n;l++)
			//{
			//	if(W[l]-W[j]<=t && c[l]==c[j])
			//	{
			//		c++;
			//	}
		
		}
		
	}
	for(int l=0;l<n;l++)
	{
		{
			if(W[l]-W[i]<=t && c[l]==c[i])
				c++;
		}
	}
}
	
