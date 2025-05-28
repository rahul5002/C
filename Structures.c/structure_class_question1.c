#include <stdio.h>
struct student
{
    char name[20];
    long int roll_no;
    float marks;
};
void main()
{
    struct student st={};
    printf("Enter the name:");
    scanf("%s", st.name);
    printf("Enter your roll no.:");
    scanf("%ld",&st.roll_no);
    printf("Enter your marks:");
    scanf("%f", &st.marks);
    printf("Name is:%s\n", st.name);
    printf("Roll no.:%ld\n", st.roll_no);
    printf("Marks:%.2f\n", st.marks);
}
