#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main()
{
    int num;
    scanf("%d",&num);

    int adjmat[num][num];
    int visited[num][num];
    int edge[num*num][2];
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            visited[i][j] = 0;
        }
    }
    int k=0;
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            scanf("%d",&adjmat[i][j]);
            if (visited[i][j] == 1)
                continue;
            else
            {
                if(adjmat[i][j] == 1)
                {
                    visited[i][j] = 1;
                    visited[j][i] = 1;
                    edge[k][0] = i;
                    edge[k][1] = j;
                    k++;
                }
            }
        }
    }
    edge[k][0] = INT_MIN;
    edge[k][1] = INT_MIN;

    int i=0;
    while(i != k )
    {
        printf("%d ~~~~~ %d\n",edge[i][0],edge[i][1]);
        i++;
    }
    printf("\n");
}
