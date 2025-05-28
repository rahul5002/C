#ifndef ARITHMETIC_H
#define ARITHMETIC_H

int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);

int add(int x, int y) 
{
    return x + y;
}
int subtract(int x, int y) 
{
    return x - y;
}
int multiply(int x, int y) 
{
    return x * y;
}
int divide(int x, int y) 
{
    if (y != 0) 
    {
        return x / y;
    }
    return 0;
}

#endif
