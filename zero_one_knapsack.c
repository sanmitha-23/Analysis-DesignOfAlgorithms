#include<stdio.h>

int max(int a,int b)
{
    if(a>b) 
    return a;
    else 
    return b;
}

int Knapsack(int n,int v[10],int wt[10],int W)
{
    int K[n+1][W+1];

    int i,j;
    
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            if(i==0 || j==0)
            K[i][j]=0;
            
            else if(wt[i-1]<=j)
            K[i][j]=max(K[i-1][j],(v[i-1]+K[i-1][j-wt[i-1]]));
            
            else
            K[i][j]=K[i-1][j];
        }
    }
    return K[n][W];
}

int main()
{
    int i,n,W,wt[10],v[10];
    
    printf("Enter the number of items:\n");
    scanf("%d",&n);
    
    printf("Enter the capacity of the Knapsack:\n");
    scanf("%d",&W);
    
    for(i=0;i<n;i++)
    {
        printf("Enter the value and weight of item %d:\n",i+1);
        scanf("%d %d",&v[i],&wt[i]); 
    }
    
    printf("The maximum profit is %d\n",Knapsack(n,v,wt,W));
    
    return 0;
}
