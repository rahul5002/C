#include<stdio.h>
int main(){
    int p=0,n=0,z=0;
    int num , x=1;
    for (;;){
        printf("Enter the number :");
        scanf("%d",&num) ;

        if (num<0) {
            n++;
        }
        else if (num>0) {
            p++;
        }
        else if (num==0){
            z++;
        }
        printf("still want to enter numbers!( type 'x' for exit else type any value)");
        scanf("%s",&x);
        if (x == 'x'){
            break;
        }
    }
    printf ("Positive values:%d\n",p);
    printf("Negative values:%d\n",n);
    printf("No. of zeroes are:%d\n",z);
    return 0;
}



