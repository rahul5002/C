#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
void linked_list_search(struct node *ptr) 
{
    while (ptr->next != NULL) 
    {
        ptr = ptr->next;
    }
    printf("Address of the node: %p\nValue of the node is: %d",(void*)ptr, ptr->data); 

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
    linked_list_search(head);
    free(head);
    free(second);
    free(third);

    return 0;
}
