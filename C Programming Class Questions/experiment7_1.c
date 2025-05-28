/* 1. Write a C program that uses functions to perform the following operations:
 a. Reading a complex number.
 b. Writing a complex number.
 c. Addition and subtraction of two complex numbers.*/
#include <stdio.h>
struct complex_number 
{
    float real,imag;
};
struct complex_number read_comp_number() 
{
    struct complex_number cnum;
    printf("Enter real part: ");
    scanf("%f", &cnum.real);
    printf("Enter imaginary part: ");
    scanf("%f", &cnum.imag);
    return cnum;
}
void write_comp_number(struct complex_number cnum) 
{
    if (cnum.imag >= 0) 
    {
        printf("Complex Number: %.2f + %.2fi\n", cnum.real, cnum.imag);
    } else 
    {
        printf("Complex Number: %.2f - %.2fi\n", cnum.real, -cnum.imag);
    }
}
struct complex_number add_comp_number(struct complex_number cnum1, struct complex_number cnum2) 
{
    struct complex_number result;
    result.real = cnum1.real + cnum2.real;
    result.imag = cnum1.imag + cnum2.imag;
    return result;
}
struct complex_number subtract_comp_number(struct complex_number cnum1, struct complex_number cnum2) 
{
    struct complex_number result;
    result.real = cnum1.real - cnum2.real;
    result.imag = cnum1.imag - cnum2.imag;
    return result;
}
int main() 
{
    struct complex_number cnum1, cnum2, sum, difference;
    printf("Enter the first complex number:\n");
    cnum1 = read_comp_number();
    printf("Enter the second complex number:\n");
    cnum2 = read_comp_number();
    printf("\nThe first complex number is:\n");
    write_comp_number(cnum1);
    printf("The second complex number is:\n");
    write_comp_number(cnum2);
    sum = add_comp_number(cnum1, cnum2);
    printf("\nThe sum of the two complex numbers is:\n");
    write_comp_number(sum);
    difference = subtract_comp_number(cnum1, cnum2);
    printf("\nThe difference of the two complex numbers is:\n");
    write_comp_number(difference);
    return 0;
}
