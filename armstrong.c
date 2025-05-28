#include <stdio.h>
#include <math.h>
int main()
{
    int number,num;
    printf("Enter a number:");
    scanf("%d",&num);
    for (;;)
    {
        number+=num%10;
        num/=10;
    }
    number=pow(number,3);
        if (number==num)
            printf("The number is an Armstrong number.");
        else 
            printf("The number is not an Armstrong number.");
    
    return 0;
}
/*
#include <stdio.h>
void main(){
int num,x=0;
printf("enter number: ");
scanf("%d",&num);
for (int c=num;c;c/=10)
    x += (c%10)*(c%10)*(c%10);
if (x==num) printf("armstrong");
else printf("not armstrong");
}*/