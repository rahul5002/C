/*WAP to read a list of integers and store it in a single dimensional array.
Write a C program to print the second largest integer in a list of integers.*/
#include <stdio.h>

int main()
{
    int n, x = 0, y = 0;
    printf("Enter the no. of elements you want in the array:");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the elements:");
        scanf("%d", &arr[i]);
    }
    printf("Array is:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > x)
            x = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > y && arr[i] != x)
            y = arr[i];
    }
    printf("Largest no.:%d\n", x);
    printf("Second Largest no.:%d", y);
    return 0;
}