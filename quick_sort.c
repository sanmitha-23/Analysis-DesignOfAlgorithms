#include<stdio.h>

int count=0;

int part(int a[10],int l,int r)
{
    int i,j,P,temp;
    
    P=a[l];
    
    i=l;
    j=r+1;
    
    while(i<=j)
    {
        do{
            i=i+1;
        }while(P>=a[i]);
        
        do{
            j=j-1;
        }while(P<a[j]);
        
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[l];
    a[l]=a[j];
    a[j]=temp;
    
    return j;
}

void quick(int a[10],int l,int r)
{
    if(l<r)
    {
        count++;
        int j=part(a,l,r);
        quick(a,l,j);
        quick(a,j+1,r);
    }
}

int main()
{
    int n,i,a[10];
    
    printf("Enter size:\n");
    scanf("%d",&n);
    
    printf("Enter elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    
    printf("Before\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    printf("\n");
    
    quick(a,0,n-1);
    
    printf("After\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    printf("\n");
    
    printf("Complexity %d\n",count);
    
    return 0;
}
