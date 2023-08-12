#include<stdio.h>

int min(int a,int b)
{
    if(a<b) return a;
    else return b;
}

int bino(int n,int k)
{
    int i,j,C[n+1][k+1];
    
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=min(i,k);j++)
        {
            if(j==0 || j==i)
            C[i][j]=1;
            
            else
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
    return C[n][k];
}

int main()
{
    int n,k;
    
    printf("Enter the values of n and k:\n");
    scanf("%d %d",&n,&k);
    
    if(n>=k)
    printf("C(%d,%d) = %d\n",n,k,bino(n,k));
    else
    printf("n should be greater than or equal to k\n");
    
    return 0;
}
