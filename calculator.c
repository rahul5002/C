#include <stdio.h>
int main()
{
    int num1,num2;
    float sum,difference,product,division;
    char i;
    printf("Enter the first number:");
    scanf("%d",&num1);
    printf("Enter the second number:");
    scanf("%d",&num2);
    for (;;){
    printf("Enter the operations that you want to be done for the two numbers:\n(a)Sum\n(b)Difference\n(c)Product\n(d)Division\n(e)Exit\n");
    scanf(" %c",&i);
    switch (i)
    {
        case 'a':
        {
            sum=num1+num2;
            printf("Sum:%d+%d=%f\n",num1,num2,sum);
            break;
        }
        case 'b':
        {
            if (num1>num2)
            {
                difference=num1-num2;
                printf("Difference:%d-%d=%f\n",num1,num2,difference);
                break;
            }
            else if (num1<num2)
            {
                difference=num2-num1;
                printf("Difference:%d-%d=%f\n",num2,num1,difference);
                break;
            }
        }
        case 'c':
        {
            product=num1*num2;
            printf("Product:%d*%d=%f\n",num1,num2,product);
            break;
        }
        case 'd':
        {
            if (num1>num2)
            {
                division=num1/num2;
                printf("Division:%d/%d=%f\n",num1,num2,division);
                break;
            }
            else if (num1<num2)
            {
                division=num2/num1;
                printf("Division:%d/%d=%f\n",num2,num1,division);
                break;
            }
        }
        case 'e':
            return 0;
        default:
        {
            printf("Invalid option,please enter again.\n");
        }
    }  
    } 
    return 0;
}