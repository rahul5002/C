#include<stdio.h>

int main()
{
    int a[10], sum = 0;
    for (int n = 0; n < 10; n++)
    {
        printf("Enter the elements:");
        scanf("%d", &a[n]);
        printf("\n");
    }
    for (int n = 0; n < 10; n++)
    {
        sum += a[n];
    }
    printf("Sum= %d\n", sum);
    return 0;

}