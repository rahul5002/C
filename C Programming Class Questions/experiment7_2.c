/*2. Write a C program to compute the monthly pay of 100 employees using each employee‗s name, basic pay.
The DA is computed as 52% of the basic pay.
Gross-salary (basic pay + DA). 
Print the employees name and gross salary.*/
 #include <stdio.h>
struct employee
{
    char name[20];
    long int basic_pay;
    long int DA;
    long int gross_salary;
};
int n;
void main()
{
    printf("Enter the number of employee entries you want to do:");
    scanf("%d", &n);
    struct employee emp[n];
    printf("\nEnter the details of employee:\n");
    for (int i = 0; i < n; i++)
    {
        getchar();
        printf("Enter employee-%d name:\n",i+1);
        scanf("%[^\n]%*c", emp[i].name);
        printf("Enter employee-%d basic pay:\n",i+1);
        scanf("%ld", &emp[i].basic_pay);
        emp[i].DA = emp[i].basic_pay * 0.52;
        emp[i].gross_salary = emp[i].basic_pay + emp[i].DA;
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("----------------------------------------------------------\n");
        printf("Name is:%s\n", emp[i].name);
        printf("Basic Pay:%ld\n", emp[i].basic_pay);
        printf("DA: %ld\n", emp[i].DA);
        printf("Gross Salary: %ld\n", emp[i].gross_salary);
        printf("\n");
    }
}
