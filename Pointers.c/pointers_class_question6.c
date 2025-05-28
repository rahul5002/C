#include <stdio.h>

int main()
{
    int num, n, count = 0;
    printf("Enter the number of elements you want in the array: ");
    scanf("%d", &num);
    int arr[num], *p;
    p = arr;
    for (int i = 0; i < num; i++)
    {
        printf("Enter the number:");
        scanf("%d", p + i);
    }
    for (int i = 0; i < num; i++)
    {
        printf("%d ", *(p + i));
    }
    printf("\n");
    printf("Enter the element you want to search in the array:");
    scanf("%d", &n);
    for (int i = 0; i < num; i++)
    {
        if (*(p + i) == n)
        {
            count++;
            printf("%d is at index no.[%d] in array.\n", n, i);
        }
    }
    if (count == 0)
        printf("%d not found in the array.", n);
    return 0;
}