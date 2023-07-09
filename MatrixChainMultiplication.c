#include<stdio.h>
#include<limits.h>

void parenthesis(int i, int j,int n,int *s,char name)
{
    if (i == j)
    {
        printf("%c%d ",name++,i);
        return;
    }
    else
    {
        printf("(");
        parenthesis(i,*((s+i*n)+j),n,s,name);
        parenthesis(*((s+i*n)+j)+1,j,n,s,name);
        printf(")");
    }
}

void mcm(int p[],int n)
{
    int m[n][n],s[n][n];
    int i,j,k,l,q;

    for(i=1;i<=n;i++)
        m[i][i]=0;

    for(l=2;l<n;l++)
    {
        for(i=1;i<=n-l+1;i++)
        {
            j=i+l-1;
            m[i][j]=INT_MAX;

            for(k=i;k<=j-1;k++)
            {
                q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);

                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    char name = 'M';

    printf("Optimal Parenthesization: ");
    parenthesis(1,n-1,n,(int*)s,name);
    printf("\n");

    printf("The minimum number of multiplications = %d\n",m[1][n-1]);
}

int main()
{
    int n,i;

    printf("Enter the number of matrices to be multiplied:\n");
    scanf("%d",&n);

    n++;

    int p[n];

    printf("Enter the dimensions of the matrices:\n");
    for(i=0;i<n;i++)
    {
        printf("Dimension %d:\n",i+1);
        scanf("%d",&p[i]);
    }

    mcm(p,n);

    return 0;

}
