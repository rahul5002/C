/*Write a program to apply left shift and right shift operator.*/
#include <stdio.h>
int main() 
{
    unsigned int num = 8;// Binary: 00001000 (Decimal: 8)
    unsigned int leftShiftResult;
    unsigned int rightShiftResult;
    leftShiftResult = num << 2;// Binary: 00001000 << 2 = 00100000 (Decimal: 32)
    printf("Left shift (8 << 2): %u\n", leftShiftResult);
    rightShiftResult = num >> 2;// Binary: 00001000 >> 2 = 00000010 (Decimal: 2)
    printf("Right shift (8 >> 2): %u\n", rightShiftResult);
    return 0;
}
