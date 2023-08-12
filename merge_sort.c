#include<stdio.h>

int count=0;

void merge(int a[10],int l,int mid,int r)
{
    int i,j,k,n1,n2;
    
    n1=mid-l+1;
    n2=r-mid;
    
    int L[n1],R[n2];
    
    for(i=0;i<n1;i++)
    L[i]=a[l+i];
    
    for(j=0;j<n2;j++)
    R[j]=a[mid+1+j];
    
    i=0;
    j=0;
    k=l;
    
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }
    
    while(i<n1)
    {
        a[k]=L[i];
        k++;
        i++;
    }
    
    while(j<n2)
    {
        a[k]=R[j];
        k++;
        j++;
    }
}

void merge_sort(int a[10],int l,int r)
{
    if(l<r)
    {
        int mid=(l+(r-1))/2;
        count++;
        merge_sort(a,l,mid);
        merge_sort(a,mid+1,r);
        merge(a,l,mid,r);
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
    
    printf("Before sort:\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    printf("\n");
    
    merge_sort(a,0,n-1);
    
    printf("After sort:\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    printf("\n");
    
    printf("Complexity:%d\n",count);
    
    return 0;
}
