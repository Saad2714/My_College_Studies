#include<stdio.h>

void bfs(int v);
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

    printf("Enter the starting node for Breadth First search\n");
    scanf("%d",&v);

    for(i=1;i<=n;i++)
        visited[i]=false;

    bfs(v);

}
void bfs(int v)
{
    int i,queue[10],top=-1,pop;
    int bottom=0;
    top++;
    queue[top]=v;
    top++;
    while(bottom != top)
    {
        pop=queue[bottom];
        bottom++;
        if(visited[pop]==false)
        {
            printf("%d",pop);
            visited[pop]=true;
        }
        else
            continue;
        for(i=0;i<n;i++)
        {
            if(a[pop][i]==1 && visited[i]==false)
            {
                top++;// push all the unvisited neighbours in the stack
                queue[top]=i;
            }
        }
    }
}
