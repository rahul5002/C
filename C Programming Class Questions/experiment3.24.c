#include <stdio.h>
int main()
{
    int population=100000,i=10,population_decrement;
    printf("The population of the country %d year is:%d\n",i,population);
    for (i=9;i>=1;i--)
    {
        population_decrement=population-(population/10);
        population=population_decrement;    
        printf("The population of the country %d year is:%d\n",i,population_decrement);
    }
    return 0;
}