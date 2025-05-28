#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr1[n];
    
    for(int i=n-1;i>=0;i--)
    {
        scanf("%d",&arr1[i]);
    }
    for(int i=0;i<=n-1;i++)
    {
        printf("%d",arr1[i]);
    }
    return 0;
}