#include <stdio.h>
int main()
{
    int num,i,first_term=1,second_term=2,next_term;
    printf("Enter the  number of terms for the series:");
    scanf("%d",&num);
    printf("%d+%d",first_term,second_term);
    for (i=1;i<=num;i++)
    {
        next_term=first_term+second_term;
        printf("+%d",next_term);
        first_term=second_term;
        second_term=next_term;
    }
    return 0;
}