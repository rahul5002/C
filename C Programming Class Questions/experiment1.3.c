#include <stdio.h>
int main()
{
    char firstname[20],lastname[20];
    int age;
    printf("Enter your firstname:\n");
    printf("Enter your lastname:\n");
    printf("Enter your age:\n");
    scanf("%s%s%d",&firstname,&lastname,&age);
    printf("Name:%s",firstname);
    printf("%s\n",lastname);
    printf("Age:%d",age);
    return 0;
}