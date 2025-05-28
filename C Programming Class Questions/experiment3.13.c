#include <stdio.h>
int main()
{
    unsigned int x1,x2,x3,y1,y2,y3;
    printf("Enter the coordinates of first point:\n");
    scanf("%d%d",&x1,&y1);
    printf("Enter the coordinates of second point:\n");
    scanf("%d%d",&x2,&y2);
    printf("Enter the coordinates of third point:\n");
    scanf("%d%d",&x3,&y3);
    if ((y2-y1)/(x2-x1)==(y3-y2)/(x3-x2)==(y1-y3/x1-x3))
        printf ("Points are collinear.");
    else
        printf("Points are non-collinear.");
    return 0;
}