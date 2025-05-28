/*Develop a function REVERSE (str) that accepts a string argument. Write a C
program that invokes this function to find the reverse of a given string*/
#include <stdio.h>
#include <string.h>
void REVERSE(char *str) 
{
    char *start = str;
    char *end = str + strlen(str) - 1;
    char temp;
    while (start < end) 
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}
int main() 
{
    char str[100];
    printf("Enter the string: ");
    scanf("%s", str);
    REVERSE(str);
    printf("Reversed string: %s\n", str);
    return 0;
}
