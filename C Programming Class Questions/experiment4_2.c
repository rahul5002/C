/*Declare a local variable inside a function and try to access it outside the
function. Compare this with accessing the global variable from within the
function.*/
#include<stdio.h>
int a=0;
int sum();
int increment();
int main()
{
    int b=2;
    while(b!=0)
    {
        b--;
        printf("%d\n",b);
    }
    printf("%d\n",sum());
    increment();
    return 0;
}
int sum ()
{
    int b;
    return b+5;
}
int increment()
{
    a++;
    printf("%d",a);
}