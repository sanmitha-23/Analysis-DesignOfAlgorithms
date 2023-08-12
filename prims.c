#include<stdio.h>

int n,i,j,a,b,u,v,min,mincost,ne=1;
int visited[10]={0},cost[10][10];

int main()
{
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    
    printf("Enter the adjacency matrix\n");
    for(i=0;i<n;i++)
    {
        printf("Enter the row %d\n",i+1);
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            cost[i][j]=999;
        }
    }
    visited[0]=1;
    while(ne<n)
    {
    for(i=0,min=999;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(cost[i][j]<min)
            {
                if(visited[i]!=0)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        
    }
        if(visited[u]==0 || visited[v]==0)
        {
            printf("Edge %d : (%d,%d) and cost = %d\n",ne++,a+1,b+1,min);
            mincost+=min;
            visited[b]=1;
        }
        cost[a][b]=cost[b][a]=999;
    }
    
    printf("Min cost spanning tree = %d\n",mincost);
    return 0;
}
