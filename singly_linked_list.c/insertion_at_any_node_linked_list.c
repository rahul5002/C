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
void insertion_after_node(struct node *prev_node, int element) 
{
    if (prev_node == NULL) 
    {
        printf("The given previous node cannot be NULL.\n");
        return;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node)); 
    new_node->data = element; 
    new_node->next = prev_node->next; 
    prev_node->next = new_node; 
}
int main() 
{
    struct node *head;
    struct node *second;
    struct node *third;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    head->data = 5;
    head->next = second;
    second->data = 9;
    second->next = third;
    third->data = 15;
    third->next = NULL;

    linked_list_traverse(head);
    insertion_after_node(second, 12);
    linked_list_traverse(head);

    free(head);
    free(second);
    free(third);

    return 0;
}
