#include<stdio.h>



void DFS(int);
//int G[10][10], visited[10],n,m; //n is number of vertices and the graph is sorted in a array G[10][10]

int t=0;
void DFS(int i)
{
    int j;
    printf("\n%d ",i);
    visited[i]=1;
    printf("%d\n",t++);


        for(j=0; j<n; j++)
        {
                if(!visited[j] && G[i][j]==1)
                {
                        DFS(j);
                //        printf("Fin of %d = ",j);
                 //       printf("%d\n",t++);
                }

        }
       // if(i==0)
       // {//
                printf("Fin of 0= ");
                printf("%d\n",t);
       // }
}
                                                        

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("Enter Mst\n");
	
	int Mst[10][3];
	for(int i=0;i<b;i++)
	{
		int p,q,w;
		scanf("%d%d%d",&p,&q,&w);	
		Mst[p][q]=w;
	}
	printf("Add edge\n");
	int l,m,n;
	scanf("%d%d%d",&l,&m,&n);



}

void Addedge(int Mst[10][3],int l,int n,int m)
{
	int j;
	Max=0;
	visited[l]=1;
	for(j=0;j<10;j++)
	{
		if(visited[j]==0 && Mst[l][j]!=0)
		{
			if(j!=n)
			{
				Addedge(Mst,j,n,m);
				if(max<Mst[l][j])
					Max=Mst[l][j]
			else
				break;
			}
		}
	}


	

