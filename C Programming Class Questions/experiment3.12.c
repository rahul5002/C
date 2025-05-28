#include<stdio.h>
int main()
{
    float BMI,w,h;
    printf("Enter your height(in mts):\n");
    scanf("%f",&h);
    printf("Enter your weight(in kgs):\n");
    scanf("%f",&w);
    BMI=(w/(h*h));
    printf(" Your BMI is: %f\n",BMI);
    if (BMI<15)
            printf("You are under Starvation category.");
    else if (BMI>15.1&&BMI<17.5)
            printf("You are under Anorexic category.");
    else if (BMI>17.6&&BMI<18.5)
            printf("You are under Underweight category.");
    else if (BMI>18.6&&BMI<24.9)
            printf("You are under Ideal category.");
    else if (BMI>25&&BMI<29.9)
            printf("You are under Overweight category.");
    else if (BMI>30&&BMI<39.9)
            printf("You are under Obese category.");
    else 
            printf("You are under Morbidity Obese category.");
    return 0;
}