#include<stdio.h>

int main()
{
    int l1,b1,l2,b2,l3,b3,perimeter1,perimeter2,perimeter3;
        printf("Enter the length of 1st rectangle:");
        scanf("%d",&l1);
        printf("Enter the breadth of 1st rectangle:");
        scanf("%d",&b1);
        perimeter1=2*(l1+b1);
        printf("Enter the length of 2nd rectangle:");
        scanf("%d",&l2);
        printf("Enter the breadth of 2nd rectangle:");
        scanf("%d",&b2);
        perimeter2=2*(l2+b2);
        printf("Enter the length of 3rd rectangle:");
        scanf("%d",&l3);
        printf("Enter the breadth of 3rd rectangle:");
        scanf("%d",&b3);
        perimeter3=2*(l3+b3);
        perimeter1>perimeter2 && perimeter1>perimeter3 ? printf("Rectangle 1 has highest perimeter"):
        perimeter2>perimeter3 && perimeter2>perimeter1 ? printf("Rectangle 2 has highest perimeter"):
        perimeter3>perimeter1 && perimeter3>perimeter2 ? printf("Rectangle 3 has highest perimeter"):printf("Either two or all Rectangles have same perimeter");
        return 0;
}