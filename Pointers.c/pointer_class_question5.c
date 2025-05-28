#include <stdio.h>

int main()
{
    int x[5] = {1, 2, 3, 4, 5};
    int *p = x;
    int i;
    for (i = 0; i < 2; i++)
    {
        int temp = *(p + i);
        *(p + i) = *(p + 4 - i);
        *(p + 4 - i) = temp;
    }
    for (i = 0; i < 5; i++)
        printf("%d ", x[i]);
    return 0;
}