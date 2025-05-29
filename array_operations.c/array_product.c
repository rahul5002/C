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
    for (int n = 0; n < 5; n++)
    {
        prod*= a[n];
    }
    printf("%d\n",prod);
    return 0;
}