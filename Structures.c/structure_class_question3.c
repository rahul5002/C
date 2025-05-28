#include <stdio.h>
struct employee
{
    char name[20];
    char address[100];
    int age;
    long int salary;
};
int n;
void main()
{
    printf("Enter the number of employee entries you want to do:");
    scanf("%d", &n);
    long int total_salary=0;
    struct employee emp[n];
    printf("\nEnter the details of employee:\n");
    for (int i = 0; i < n; i++)
    {
        getchar();
        printf("Enter employee-%d name:\n",i+1);
        scanf("%[^\n]%*c", emp[i].name);
    }
    for (int i = 0; i < n; i++)
    {
        getchar();
        printf("Enter employee-%d address:\n",i+1);
        scanf("%[^\n]%*c", emp[i].address);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter employee-%d age:\n",i+1);
        scanf("%d", &emp[i].age);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter employee-%d salary:\n",i+1);
        scanf("%ld", &emp[i].salary);
        total_salary+=emp[i].salary;
    }
    for (int i = 0; i < n; i++)
    {
        printf("Name is:%s\n", emp[i].name);
        printf("Address:%s\n", emp[i].address);
        printf("Age:%d\n", emp[i].age);
        printf("Salary:%ld\n", emp[i].salary);
        printf("\n");
    }
    long int avg_salary=total_salary/n;
    printf("Average Salary:%ld",avg_salary);
}
