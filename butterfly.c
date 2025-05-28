#include<stdio.h>

int main() {
    int n;
    printf("Enter the number of rows:");
    scanf("%d",&n);
    // Upper half of the butterfly
    for(int i=1; i<=n; i++) 
    {
        for(int m=1; m<=2*i-1; m++) 
        {
            printf("*");
        }
        for(int k = (2*i + 1); k < (2*n + 1); k++) 
        {  
            printf(" ");
            printf(" ");
        }
        for(int m=2*i-1;m>=1; m--) 
        {
            printf("*");
        }
        printf("\n");
    }
    
    // Lower half of the butterfly
    for(int i=n; i>=1; i--) 
    {
        for(int m=1; m<=2*i-1; m++) 
        {
            printf("*");
        }
        for(int k = (2*i + 1); k < (2*n + 1); k++) 
        {  
            printf(" ");
            printf(" ");
        }
        for(int m=1; m<=2*i-1; m++) 
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
