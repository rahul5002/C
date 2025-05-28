/*Declare variables within different code blocks (enclosed by curly braces) and
test their accessibility within and outside those blocks.*/
#include<stdio.h>
int increment();
int decrement();
int main()
{
    int num1=5,num2=10;
    printf("%d\n",num1+num2);
    increment();
    decrement();
    return 0;
}
int increment()
{
    int num1;
    num1++;
    printf("%d\n",num1);
}
int decrement()
{
    int num1;
    num1--;
    printf("%d\n",num1);
}