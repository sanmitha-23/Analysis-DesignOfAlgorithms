#include<stdio.h>

int count=0;

void sel(int a[10],int n)
{
    int i,j,min,temp;
    
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            count++;
            if(a[j]<=a[min])
            {
                min=j;
            }
            
            if(i!=min)
            {
                temp=a[i];
                a[i]=a[min];
                a[min]=temp;
            }
        }
    }
}

int main()
{
    int n,i,a[10];
    
    printf("Enter size:\n");
    scanf("%d",&n);
    
    printf("Enter elements:\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    
    printf("Before sorting:\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    printf("\n");
    
    sel(a,n);
    
    printf("After sorting:\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    printf("\n");

    printf("Complexity:%d\n",count);
    
    return 0;
}
