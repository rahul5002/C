#include <stdio.h>
int main()
{
    int num;
    printf("Enter a number:");
    scanf("%d",&num);
    if(num%3==0&num%5==0)
    printf("The number %d is divisible by 3 and 5.",num);
    else
    printf("Number is not divisible by 3 and 5.");
    return 0;
}