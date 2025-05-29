#include <stdio.h>

int main()
{
    int n, b, x;
    printf("Enter the number of elements you want: ");
    scanf("%d", &n);
    int a[n + 1];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("Enter the index where you want to insert (0 to %d): ", n);
    scanf("%d", &x);
    if (x < 0 || x > n)
    {
        printf("Invalid index!\n");
        return 1;
    }
    printf("Enter the element you want to add: ");
    scanf("%d", &b);
    printf("Array before insertion: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    // Shifting elements to the right to make space for the new element
    for (int i = n; i > x; i--)
    {
        a[i] = a[i - 1];
    }
    a[x] = b;
    n++;      
    printf("Array after insertion: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    
    return 0;
}
