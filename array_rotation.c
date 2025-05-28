#include<stdio.h>

int main()
{
    int m,x;
    printf("Enter the no.of elements you want in the array:");
    scanf("%d", &m);
    printf("Enter the no.of elements that you want to rotate in the array:");
    scanf("%d", &x);
    int a[m];
    for (int i=0;i<m;i++)
    {
        printf("Enter the elements:");
        scanf("%d", &a[i]);
    }
    printf("Array is:\n");
    for (int i=0;i<m;i++)
    {
        printf("%d ", a[i]);
        printf("\t");
    }
    for (int i=0;i<m;i++)
    {
        a[i]=a[i-1];
        a[0]=a[i];
    }
    for (int i=0;i<m;i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}