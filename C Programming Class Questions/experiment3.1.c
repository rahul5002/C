#include <stdio.h>
int main()
{
    int a1,a2,a3,sum,s1,s2,s3,i;
    printf("Enter the angles of the polygon:");
    scanf("%d%d%d",&a1,&a2,&a3);
    //angle sum property of triangle states that the sum of angles of a triangle is 180 degree.
    sum=a1+a2+a3;
    if (sum==180)
        printf("It is a triangle.\n");
    else
    {
        printf("It is not a triangle.\n");
        return 0;
    }
    printf("Enter the side of the triangle:\n");
    //sum of two sides of a triangle is smaller or equal to the third side.
    scanf("%d%d%d",&s1,&s2,&s3);
    if (s1 + s2 <= s3 || s1 + s3 <= s2 || s2 + s3 <= s1)
    {
        printf("It is not a triangle.\n");
        return 0;
    }
    for (;;){
    printf("Enter option to check the type of triangle:\n 1. Isosceles triangle\n 2. Scalene triangle\n 3. Right angle triangle\n 4. Equilateral triangle\n 5. Exit\n");
    scanf("%d",&i);
    
    switch(i)
    {
        case 1:
            if (s1==s2||s2==s3||s1==s3)
                printf("It is an isosceles triangle.\n");
            else
                printf("It is not an isosceles triangle.\n");            
                break;
        case 2:
            if (s1!=s2&&s2!=s3&&s1!=s3)
                printf("It is a scalene triangle.\n");
            else
                printf("It is not a scalene triangle.\n");  
                break;
        case 3:
            if (a1==90||a2==90||a3==90)
                printf("It is a right angle triangle.\n");
            else
                printf("It is not a right angle triangle.\n");
                break;
        case 4:
            if (s1==s2&&s2==s3&&s1==s3)
                printf("It is an equilateral triangle.\n");
            else
                printf("It is not an equilateral triangle.\n");
                break;
        case 5:
                return 0;
         default:
                printf("Invalid option. Please try again.\n");

    }
    }
    return 0;
}
