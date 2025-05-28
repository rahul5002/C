#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr1[n],arr2[n];
    
    for(int i=0;i<n;i++)
    {
        scanf("%d\n",&arr1[i]);
        printf("%d\n ",arr1[i]);
        arr2[i]=arr1[i];
        printf("%d\n",arr2[i]);
    }
    return 0;
}