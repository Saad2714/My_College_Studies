#include<stdio.h>
int G[10][10];
int visited[10];
int queue[14];
int h=0;
int t=0;
void bfs(int);
int n,m;

void enqueue(int);
void enqueue(int x)
{
	queue[t]=x;
	t++;
}

int dequeue();
int  dequeue()
{
	int f=queue[h];
	h++;
	return f;

}
int front()
{
	return queue[h];
}
int isempty();
int isempty()
{
	if(h==t)
		return 1;
	else
		return 0;
}


int main()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			G[i][j]=0;
	}
	int a,b;
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		G[a][b]=1;
		G[b][a]=1;
	}

/* 	G[1][0]=1;
        G[0][1]=1;
        G[2][1]=1;
        G[1][2]=1;
        G[2][3]=1;
        G[3][2]=1;
        G[2][6]=1;
        G[6][2]=1;
        G[1][4]=1;
        G[4][1]=1;
        G[4][5]=1;
        G[5][4]=1;
        G[1][5]=1;
        G[5][1]=1;*/

for(i=0;i<10;i++)
	visited[i]=0;


bfs(0);

}


void bfs(int i)
{
	int j;
	enqueue(i);
	visited[i]=1;
	while(isempty()!=1)
	{
		int k=dequeue();
		printf("%d\n",k);

		for(j=0;j<7;j++)
		{
			if(!visited[j] && G[k][j])
			{
				enqueue(j);
				visited[j]=1;
			}

		}

		//k=front();
	}
}



