#include<stdio.h>

int count=0;

void topo()
{
    int n,i,j,u,k=1,sum=0;
    
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    
    int sol[n+1],s[n+1],indeg[n+1],a[n+1][n+1];
    
    printf("Enter the adjacency matrix:\n");
    for(i=1;i<=n;i++)
    {
        printf("Enter the row %d:\n",i);
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    
    for(j=1;j<=n;j++)
    {
        sum=0;
        for(i=1;i<=n;i++)
            sum=sum+a[i][j];
        indeg[j]=sum;
    }
    
    int top=-1;
    
    for(i=1;i<=n;i++)
    {
        if(indeg[i]==0)
        s[++top]=i;
    }
    
    while(top!=-1)
    {
        u=s[top--];
        sol[k]=u;
        k++;
        
        for(j=1;j<=n;j++)
        {
            count++;
            if(a[u][j]>0)
            {
                indeg[j]-=1;
                if(indeg[j]==0)
                s[++top]=j;
            }
        }
    }
    
    printf("Linear sequence of vertices:\n");
    for(k=1;k<=n;k++)
    printf("%d\t",sol[k]);
    printf("\n");
}

int main()
{
    topo();
    printf("Topological sort count = %d\n",count);
    
    return 0;
}
