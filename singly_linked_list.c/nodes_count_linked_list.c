#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
void linked_list_node_count(struct node *ptr) 
{
    int count=0;
    while (ptr != NULL) 
    {
        count+=1;
        printf("%d ", ptr->data); 
        ptr = ptr->next;
    }
    printf("\nTotal number of nodes: %d\n", count);
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
    linked_list_node_count(head);
    free(head);
    free(second);
    free(third);

    return 0;
}
