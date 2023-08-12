#include<stdio.h>

int min(int a,int b)
{
    if(a<b) return a;
    else return b;
}

void floyd(int a[10][10],int n)
{
    int i,j,k;
    
    for(k=0;k<=n;k++)
    {
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                if(i==j)
                a[i][j]=0;
                else
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
}

int main()
{
    int n,i,j,a[10][10];
    
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        printf("Enter row %d:\n",i+1);
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    }
    
    floyd(a,n);
    
    printf("Resultant matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        printf("%d\t",a[i][j]);
        printf("\n");
    }
    
    return 0;
}
