#include <stdio.h>

int main()
{
    int n,i,j,key=0;
    printf("Enter the no. of elements you want in the array:");
    scanf("%d\n",&n);
    int a[n];
    for (i= 0; i < n; i++)
    {
        printf("Enter the elements:");
        scanf("%d",&a[i]);
        printf("\n");
    }
    printf("Unsorted array:");
    for (i = 0; i < n; i++)
    {
        printf("%d",a[i]);
        printf("\t");
    }printf("\n");
    for(j=1;j<n;j++)
    {
        key=a[j];
        i=j-1;
        while(i>0&&a[i]>key)
        {
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
    }
    printf("Sorted array:");
    for (i = 0; i < n; i++)
    {
        printf("%d",a[i]);
        printf("\t");
    }
    return 0;
}