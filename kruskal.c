#include<stdio.h>

int n,i,j,a,b,u,v,ne=1,min,mincost;
int parent[10],cost[10][10];

int find(int i)
{
    while(parent[i])
    i=parent[i];
    
    return i;
}

int uni(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}

int main()
{
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    
    printf("adjacency matrix\n");
    for(i=0;i<n;i++)
    {
        printf("Row %d:\n",i+1);
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            cost[i][j]=999;
        }
    }
    
    while(ne<n)
    {
        for(i=0,min=999;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        
        u=find(u);
        v=find(v);
        
        if(uni(u,v))
        {
            printf("Edge %d : (%d,%d) and cost = %d\n",ne++,a+1,b+1,min);
            mincost+=min;
        }
        cost[b][a]=cost[a][b]=999;
    }
    
    printf("Min cost of spanning tree : %d\n",mincost);
    
    return 0;
}
