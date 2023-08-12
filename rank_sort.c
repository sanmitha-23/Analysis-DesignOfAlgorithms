#include<stdio.h>

int count =0;

void rank(int a[10],int r[10],int n)
{
    int i,j,b[10];
    
    for(i=1;i<n;i++)
    {
        for(j=0;j<=i-1;j++)
        {
            count++;
            if(a[j]<=a[i])
            r[i]++;
            
            else
            r[j]++;
        }
    }
    
    for(i=0;i<n;i++)
    b[r[i]]=a[i];
    
    printf("After sorting:\n");
    for(i=0;i<n;i++)
    printf("%d\t",b[i]);
    printf("\n");
}

int main()
{
    int n,i,a[10],r[10];
    
    printf("Enter the size:\n");
    scanf("%d",&n);
    
    printf("Enter elements:\n");
    for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
      r[i]=0;
    }
    
    printf("Before sorting:\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    printf("\n");
    
    rank(a,r,n);
    
    printf("Time complexity = %d\n",count);
    
    return 0;
    
}
*/

//Insertion sort 
/*
#include<stdio.h>

int count=0;

void ins(int a[10],int n)
{
    int i,j,key;
    
    for(i=1;i<=n-1;i++)
    {
        count++;
        key=a[i];
        j=i-1;
        
        while(j>=0 && a[j]>key)
        {
            count++;
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
}

int main()
{
    int n,i,a[10];
    
    printf("Enter size:\n");
    scanf("%d",&n);
    
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    
    printf("Before sorting:\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    printf("\n");
    
    ins(a,n);
    
    printf("After sorting:\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    printf("\n");
    
    printf("Complexity %d\n",count);
    
    return 0;
}
