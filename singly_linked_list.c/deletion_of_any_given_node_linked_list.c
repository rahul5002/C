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
void deletion_of_any_node(struct node **head,int position) 
{
    if (*head == NULL) 
    {
        printf("List is already empty.\n");
        return;
    }

    struct node *temp = *head;

    if (position == 0) 
    {
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct node *prev = NULL;
    for (int i = 0; temp != NULL && i < position; i++) 
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) 
    {
        printf("Position out of range.\n");
        return;
    }

    prev->next = temp->next;
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
    deletion_of_any_node(&head,1);
    printf("After deletion of node:\n");
    linked_list_traverse(head);

    while (head != NULL) 
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
