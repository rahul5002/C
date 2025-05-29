#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int coefficient;
    int exponent;
    struct node* next;
};

struct node* head = NULL;
struct node* temp = NULL;
struct node* new_node = NULL;

void insert(int coefficient, int exponent) 
{
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->coefficient = coefficient;
    new_node->exponent = exponent;
    new_node->next = NULL;

    if (head == NULL) 
    {
        head = new_node;
    } 
    else 
    {
        temp = head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void traverse(struct node* head) 
{
    temp = head;
    while (temp != NULL) 
    {
        if (temp->exponent == 0)
            printf("%d", temp->coefficient);
        else
            printf("%dx^%d", temp->coefficient, temp->exponent);

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
    printf("\n");
}
int main() 
{
    int coefficient, exponent, n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coefficient, &exponent);
        insert(coefficient, exponent);
    }

    printf("The polynomial is: ");
    traverse(head);

    return 0;
}
