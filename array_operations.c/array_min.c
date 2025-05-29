#include <stdio.h>

int main()
{
    int a[5], prod = 1;
    for (int n = 0; n < 5; n++)
    {
        printf("Enter the elements:");
        scanf("%d", &a[n]);
        printf("\n");
    }
    int min=0;
    for(int i=0;i<5;i++)
    {
        if(a[i]<min)
        min=a[i];
    }
    return min;
    return 0;
}