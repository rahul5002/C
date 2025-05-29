#include <stdio.h>
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements of the array:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int median;
    if (n % 2 == 0) 
    {
        median = (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
    else
    {
        median = arr[n / 2];
    }
    printf("The median of the array is: %d\n", median);

    return 0;
}
