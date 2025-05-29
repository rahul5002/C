#include <stdio.h>

int main()
{
    int item;
    int a[5];
    for (int n = 0; n < 5; n++)
    {
        printf("Enter element %d: ", n + 1);
        scanf("%d", &a[n]);
    }
    printf("Enter the item you want to search: ");
    scanf("%d", &item);
    for (int k = 0; k < 5; k++)
    {
        if (a[k] == item)
        {
            printf("Item found at index %d\n", k);
            return 0;
        }
    }
    printf("Item not found in the array.\n");
    return -1;
}
