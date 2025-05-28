#include <stdio.h>
int add(int a, int b)
{
    return a + b;
}
void main()
{
    int (*ptr)(int, int) = &add;
    printf("%d",(*ptr)(10,2));
}