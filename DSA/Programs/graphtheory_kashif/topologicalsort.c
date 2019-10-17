#include<stdio.h>
int visited[10];
//for(int t=0;t<10;t++)
  //     visited[t]=0;
int T[10];
int d[1][10];
int h=0;
void topologicalsort(int k[10][10],int,int);
int main()
{
	int a,b,s;
	scanf("%d%d%d",&a,&b,&s);
	int G[10][10];
	int W[10][10];
	
	for(int i=0; i<a; i++)
        {
                for(int j=0; j<a; j++)
                {
                        //printf("G[%d][%d]\n",i,j);
                        G[i][j]=0;
			W[i][j]=0;
			visited[i]=0;
			T[i]=0;
                }

        }
	for(int j=0;j<a;j++)
		d[s][j]=1000;
	d[s][s]=0;
	
        int p,q,r;
        for(int j=0;j<b;j++)
        {
                        scanf("%d%d%d",&p,&q,&r);
                        G[p][q]=1;
			W[p][q]=r;
        }

	topologicalsort(G,a,s);
	//for(int i=0;i<a;i++)
	//{
	//	for(int j=0;j<a;j++)
	//		G[
	//int f=T[a-1];
	//for(int i=0;i<a;i++)
	//	visited[i]=0;
//	for (int k=a-1;k>=0;k--)
//		printf("%d\n",T[k]);
	for(int f=0;f<a;f++)
	{
		int k=T[a-f-1];
		//rintf("%d\n",T[f]);
		for(int j=0;j<a;j++)
		{
			if(G[k][j]==1)
			{
				if(d[s][j]>d[s][k]+W[k][j])
					d[s][j]=d[k][s]+W[k][j];
					
			}
		}
	}
	for (int i=0;i<a;i++)
	{
			printf("%d\n",d[s][i]);
		//	printf("%d\n",T[i]);
	}

}

int t=0;
void topologicalsort(int al[10][10],int n,int i)
{
	//visited[i]=1;
	//printf("%d",i);
	for(int t=0;t<n;t++)
	{
		if(al[i][t]==1	&& visited[t]==0)
		{		visited[i]=1;
				topologicalsort(al,n,t);
				visited[i]=0;
				//visited[i]=1;
				
				
				

		}
		else if(al[t][i]==1 && visited[t]==0)
		{
			//visited[t]=1;
			topologicalsort(al,n,t);
			visited[i]=0;

			
		}
		//visited[i]=1;
		
	}
		visited[i]=1;
		
		if(h<n)
			T[h++]=i;
		return;

	//printf("%d %d\n",i,t++);
	//T[h++]=i;


}	
	
