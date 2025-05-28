#include <stdio.h>
int main()
{
    float c,f;  
    printf("Enter temperature in celsius:\n");
    scanf("%f",&c);
    f=(c*(9.0/5.0)+32);
    printf("Temperature in fahrenheit:%f\n",f);
    return 0;
}