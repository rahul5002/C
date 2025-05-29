#include <stdio.h>

int main()
{
    int a[10];
    for (int n = 0; n < 10; n++)
    {
        printf("Enter the elements:");
        scanf("%d", &a[n]);
        printf("\n");
    }
    for (int n = 0; n < 10; n++)
    {
        printf("%d\t ",a[n]);
    }
    return 0;
}