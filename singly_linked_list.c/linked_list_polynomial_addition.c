#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int coefficient;
    int exponent;
    struct node* next;
};

struct node* head1 = NULL;
struct node* head2 = NULL;
struct node* result = NULL;
struct node* temp = NULL;
struct node* new_node = NULL;

void insert(struct node** head, int coefficient, int exponent) 
{
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->coefficient = coefficient;
    new_node->exponent = exponent;
    new_node->next = NULL;

    if (*head == NULL) 
    {
        *head = new_node;
    } 
    else 
    {
        temp = *head;
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

struct node* add_polynomials(struct node* head1, struct node* head2) 
{
    struct node* p1 = head1;
    struct node* p2 = head2;
    struct node* result = NULL;

    while (p1 != NULL && p2 != NULL) 
    {
        if (p1->exponent == p2->exponent) 
        {
            insert(&result, p1->coefficient + p2->coefficient, p1->exponent);
            p1 = p1->next;
            p2 = p2->next;
        } 
        else if (p1->exponent > p2->exponent) 
        {
            insert(&result, p1->coefficient, p1->exponent);
            p1 = p1->next;
        } 
        else 
        {
            insert(&result, p2->coefficient, p2->exponent);
            p2 = p2->next;
        }
    }

    while (p1 != NULL) 
    {
        insert(&result, p1->coefficient, p1->exponent);
        p1 = p1->next;
    }

    while (p2 != NULL) 
    {
        insert(&result, p2->coefficient, p2->exponent);
        p2 = p2->next;
    }

    return result;
}

int main() 
{
    int coefficient, exponent, n;

    printf("Enter the number of terms for the first polynomial: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coefficient, &exponent);
        insert(&head1, coefficient, exponent);
    }

    printf("Enter the number of terms for the second polynomial: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coefficient, &exponent);
        insert(&head2, coefficient, exponent);
    }

    result = add_polynomials(head1, head2);

    printf("The first polynomial is: ");
    traverse(head1);

    printf("The second polynomial is: ");
    traverse(head2);

    printf("The sum of the two polynomials is: ");
    traverse(result);

    return 0;
}
