/*Write a program to apply bitwise OR, AND and NOT operators on bit level.*/
#include <stdio.h>
int main() 
{
    unsigned int num1 = 5;// Binary: 00000101
    unsigned int num2 = 3;// Binary: 00000011
    unsigned int result;
    result = num1 | num2;// Binary: 00000101 | 00000011 = 00000111
    printf("Bitwise OR (5 | 3): %u\n", result);
    result = num1 & num2;// Binary: 00000101 & 00000011 = 00000001
    printf("Bitwise AND (5 & 3): %u\n", result);
    result = ~num1;// Binary: ~00000101 = 11111010
    printf("Bitwise NOT (~5): %u\n", result);
    return 0;
}
