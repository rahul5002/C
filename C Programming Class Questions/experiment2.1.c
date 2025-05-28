#include <stdio.h>
int main()
{
    int x,y,area,perimeter;    
    printf("Enter the length of rectangle:\n");
    scanf("%d",&x);
    printf("Enter the breadth of rectangle:\n");
    scanf("%d",&y);
    area =(x*y);
    perimeter =(2*(x+y));
    printf("area:%d\n",area);
    printf("perimeter:%d",perimeter);
    return 0;
}