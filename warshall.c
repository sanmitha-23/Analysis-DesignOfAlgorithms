#include<stdio.h>

void Warshall(int a[20][20],int n)
{
    int i,j,k;
    
    for(k=0;k<=n;k++)
    {
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            a[i][j] = (a[i][j] || (a[i][k] && a[k][j]));
        }
    }
}

int main()
{
    int n,i,j,a[20][20];
    
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        printf("Enter row %d\n",i+1);
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    }
    
    Warshall(a,n);
    
    printf("Transitive closure\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        printf("%d\t",a[i][j]);
        
        printf("\n");
    }
    
    return 0;
}
