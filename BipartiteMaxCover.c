#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define x 3
#define y 3

bool biGraph[x][y];

bool bpMax(int u, bool visited[], int a[])
{
    int v;
    for (v=0;v<y;v++)
    {
        if (biGraph[u][v] && !visited[v])
        {
            visited[v] = true;
            if(a[v] < 0 || bpMax(a[v],visited,a))
            {
                a[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxMatch()
{
    int a[y];

    for(int i = 0; i<y; i++)
        a[i] = -1;

    int count = 0;

    for (int u = 0; u < x; u++)
    {
        bool visited[y];
        for(int i = 0; i<y; i++)
            visited[i] = false;
        if(bpMax(u,visited,a))
            count++;
    }

    return count;
}

int main()
{
    printf("Enter the adjacency matrix for the bipartite graph:\n");

    int i,j;
    int graph[x][y];

    for(i=0;i<x;i++)
    {
        printf("Enter row %d:\n",i+1);
        for(j=0;j<y;j++)
        {
            scanf("%d",&graph[i][j]);
            biGraph[i][j]=graph[i][j];
        }
    }
    printf("\n");
    printf("Maximum matching for the bipartite graph is : %d\n",maxMatch());

    return 0;
}
