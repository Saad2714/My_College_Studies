#include<stdio.h>
#include<limits.h>

int main()
{
    int n =0;
    scanf("%d ",&n);

    int adj[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }

    int current[n], distance[n], visited[n*n]; //current can be made using min heap
    
    for(int i=0;i<n;i++)
    {
        current[i] = INT_MAX;
        distance[i] = INT_MIN;
    }
    
    current[0] = 0; // for source as weight will be 0
    distance[0] = 0;
    int i=0;
    while(1)
    {
        for(int j=0;j<n;j++)
        {
            if(adj[i][j] < current[i] && adj[i][j] >=0 && distance[i] == INT_MIN)
            {   
                printf("YE!\n");
                current[i] = adj[i][j];
            }
        }
        int min= INT_MAX, min_index =0;
        for(int j=0;j<n;j++)
        {
            if(min > current[j])
            {
                min = current[j];
                min_index = j;
            }
        }
        if(min == INT_MAX)
        {
            break;
        }
        distance[min_index] = distance[i] + current[min_index];
        current[min_index] = INT_MAX;
    }
    for(int i=0;i<n;i++)
        printf("%d ",distance[i]);
    printf("\n");

}
