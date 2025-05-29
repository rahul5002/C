#include<stdio.h>
#include<stdlib.h>
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
    free(head);
    free(second);
    free(third);

    return 0;
}
