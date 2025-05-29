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
    int low = 0;
    int high = 4; 
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        
        if (a[mid] == item)
        {
            printf("Item found at index %d\n", mid);
            return 0; 
        }
        else if (item < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    printf("Item not found in the array.\n");
    return -1;
}
