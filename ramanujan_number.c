#include <stdio.h>
#include <math.h>

int main() {
    int a, b, num, limit, count = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter the limit for checking: ");
    scanf("%d", &limit);
    
    for (a = limit; a != 0; a--) {
        for (b = a; b != 0; b--) {  // Ensure b <= a to avoid repeats
            double n1 = pow(a, 3);
            double n2 = pow(b, 3);
            if (n1 + n2 == num) {
                printf("Factors of Ramanujan's number are: %d, %d\n", a, b);
                count++;
            }
        }
    }
    
    if (count == 2)
        printf("It is a Ramanujan's number.\n");
    else
        printf("It is not a Ramanujan's number.\n");
        
    return 0;
}
