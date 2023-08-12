#include<stdio.h>

int main()
{
    int n,i,j,u,v,w,num,min;
    int dist[15],s[15],cost[15][15];
    
    printf("Enter the number of nodes;\n");
    scanf("%d",&n);
    
    printf("Enter the adjacency matrix:\n");
    for(i=1;i<=n;i++)
    {
        printf("Enter row %d:\n",i);
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            cost[i][j]=999;
        }
    }
    
    printf("Enter the source vertex:\n");
    scanf("%d",&v);
    
    for(i=1;i<=n;i++)
    {
        s[i]=0;
        dist[i]=cost[v][i];
    }
    
    s[v]=1;
    dist[v]=0;
    
    for(num=2;num<=n-1;num++)
    {
        min=999;
        for(w=1;w<=n;w++)
        {
            if((s[w]==0) && (dist[w]<min))
            {
                min=dist[w];
                u=w;
            }
        }
        s[u]=1;
        
        for(w=1;w<=n;w++)
        {
            if(s[w]==0)
            {
                if(dist[w]>(dist[u]+cost[u][w]))
                dist[w]=dist[u]+cost[u][w];
            }
        }
    }
    
    printf("VERTEX\tDESTINATION\tCOST\n");
    for(i=1;i<=n;i++)
    {
        printf("  %d\t    %d\t  \t%d\n",v,i,dist[i]);
    }
    
    return 0;
}
