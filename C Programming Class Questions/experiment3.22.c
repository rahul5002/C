#include <stdio.h>
int main()
{
    int number,i,a,product;
    printf("Enter the number:");
    scanf("%d",&number);
    printf("Enter the multiple upto which you want to print:");
    scanf("%d",&a);
    for (i=1;i<=a;i++)
    {
        product=(number*i);
        printf("%d*%d= %d\n",number,i,product);

    }
return 0;
}