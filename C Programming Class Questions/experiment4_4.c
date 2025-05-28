/*Declare a static local variable inside a function. Observe how its value
persists across function calls.*/
#include<stdio.h>
int sum();
int main()
{
    int a;
    while(a!=0)
    {
        a--;
        printf("%d\n",a);
    } 
    printf("%d\n",sum());
    return 0;
}
int sum()
{
    static int a=5;
    return a+2;
}