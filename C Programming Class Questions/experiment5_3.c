/*WAP to read a list of integers and store it in a single dimensional array.
Write a C program to find the frequency of a particular number in a list of integers.*/
#include <stdio.h>

int main()
{
    int n, x, count = 0;
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
    printf("Enter the element for which you want to find the frequency in the array:");
    scanf("%d", &x);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            count++;
    }
    printf("The frequency of the number is: %d", count);
    return 0;
}
