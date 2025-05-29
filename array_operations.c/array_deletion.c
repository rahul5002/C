#include <stdio.h>

int main()
{
    int n, x;
    printf("Enter the number of elements you want: ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("Enter the index of the element you want to delete (0 to %d): ", n - 1);
    scanf("%d", &x);
    if (x < 0 || x >= n)
    {
        printf("Invalid index!\n");
        return 1;
    }
    printf("Array before deletion: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    // Shifting elements to the left to delete the element
    for (int i = x; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
    printf("Array after deletion: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    
    return 0;
}
