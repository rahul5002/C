/*WAP to read a list of integers and store it in a single dimensional array. 
Write a C program to count and display positive, negative, odd, and even numbers in an array.*/
#include<stdio.h>

int main()
{
    int num, p = 0, n = 0, z = 0, even = 0, odd = 0;
    printf("Enter the number of elements you want in the array: ");
    scanf("%d", &num);
    int arr[num];
    for (int i = 0; i < num; i++) 
    {
        printf("Enter the elements:");
        scanf("%d", &arr[i]);
    }
    printf("\n");
    printf("Array is: ");
    for (int i = 0; i < num; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Even numbers: ");
    for (int i = 0; i < num; i++) 
    {
        if (arr[i] % 2 == 0) 
        {
            even++;
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
    printf("Odd numbers: ");
    for (int i = 0; i < num; i++) 
    {
        if (arr[i] % 2 != 0) 
        {
            odd++;
            printf("%d ", arr[i]);
        }
    }

    printf("\n");
    printf("Positive numbers: ");
    for (int i = 0; i < num; i++) 
    {
        if (arr[i] > 0) 
        {
            p++;
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
    printf("Negative numbers: ");
    for (int i = 0; i < num; i++) 
    {
        if (arr[i] < 0) 
        {
            n++;
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
    printf("Zeroes: ");
    for (int i = 0; i < num; i++) 
    {
        if (arr[i] == 0) 
        {
            z++;
            printf("%d ", arr[i]);
        }
    }
    printf("\n\n");
    printf("Count:\n");
    printf("Even values: %d\n", even);
    printf("Odd values: %d\n", odd);
    printf("Positive values: %d\n", p);
    printf("Negative values: %d\n", n);
    printf("No. of zeroes: %d\n", z);

    return 0;
}
