#include<stdio.h>

void dfs(int v, int discovery[], int finish[]);
typedef enum boolean{false,true}bool;
int n,a[10][10];
bool visited[10];

int main()
{
    int i,j,v;
    printf("Enter the no. of nodes in the graph\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix \n");

    for(i=1;i<=n;i++)

    {

        for(j=1;j<=n;j++)

        {

            scanf("%d",&a[i][j]);

        }
    }

    printf("Enter the starting node for Depth First search\n");
    scanf("%d",&v);

    for(i=1;i<=n;i++)
        visited[i]=false;
    
    int discovery[n],finish[n];
    dfs(v,discovery,finish);
    /*for(int i=0;i<n;i++)
    {
        printf("%d ~~~ %d : %d \n ",discovery[i],finish[i],i);
    }*/
}
void dfs(int v,int discovery[],int finish[])
{
    int time =0 ;
    int i,stack[10],top=-1,pop;
    top++;
    stack[top]=v;
    discovery[v] = time;
    time++;

    while(top>=0)
    {
        pop=stack[top];
        top--;
        if(visited[pop]==false)
        {
            printf("%d",pop);
            visited[pop]=true;
        }
        else
            continue;
        for(i=n;i>=1;i--)
        {
            if(a[pop][i]==1 && visited[i]==false)
            {
                discovery[i] = time ++;
                top++;// push all the unvisited neighbours in the stack
                stack[top]=i;
            }
        }
    }
}
