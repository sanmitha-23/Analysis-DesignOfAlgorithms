#include<stdio.h>
#include<string.h>

int max(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}

void lcs(char s1[20],char s2[20])
{
    int i,j,m,n,x,mat[20][20];
    
    m=strlen(s1);
    n=strlen(s2);
    
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            mat[i][j]=0;
            
            else if(s1[i-1]==s2[j-1])
            mat[i][j]=1+mat[i-1][j-1];
            
            else
            mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
        }
    }
    
    i=m;
    j=n;
    x=mat[i][j];
    
    char ss[x+1];
    ss[x]='\0';
    
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            ss[x-1]=s1[i-1];
            x--;
            i--;
            j--;
        }
        else if(mat[i-1][j]>mat[i][j-1])
        i--;
        else
        j--;
    }
    
    printf("Longest common Subsequence is %s\n",ss);
    printf("Length of LCS is %d\n",mat[m][n]);
}

int main()
{
    char s1[20],s2[20];
    
    printf("Enter first string:\n");
    scanf("%s",s1);
    
    printf("Enter second string:\n");
    scanf("%s",s2);
    
    lcs(s1,s2);
    
    return 0;

}
