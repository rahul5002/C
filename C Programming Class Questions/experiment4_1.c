//Declare a global variable outside all functions and use it inside various 
//functions to understand its accessibility.
#include<stdio.h>
int a=0;
int sum(int b)
{
    return a+b;
}
int main()
{
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        a++;
        printf("%d\n",a);
    }
    printf("a+b=%d\n",sum(5));
    return 0;
}