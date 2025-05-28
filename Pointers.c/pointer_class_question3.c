#include<stdio.h>

int main()
{
    int arr[14]={25,30,35,40,45,50,55,60,65,70,75,80,85,90},*p;
    for(p=arr+2;p<arr+8;p=p+2)
        printf("%d\t",*p);
    return 0;
}