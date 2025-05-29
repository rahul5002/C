#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};
void linked_list_traverse(struct node *ptr) 
{
    while (ptr != NULL) 
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void deletion_at_beg(struct node **head) 
{
    if (*head == NULL) 
    {
        printf("List is already empty.\n");
        return;
    }

    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

int main() 
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));


    head->data = 5;
    head->next = second;
    second->data = 9;
    second->next = third;
    third->data = 15;
    third->next = NULL;

    printf("Original linked list:\n");
    linked_list_traverse(head);
    deletion_at_beg(&head);
    printf("After deletion at beginning:\n");
    linked_list_traverse(head);

    while (head != NULL) 
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
