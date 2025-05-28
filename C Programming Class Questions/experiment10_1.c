/*Write a program to create a simple linked list in C using pointer and structure.*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
int main() 
{
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;      
    head->next = second; 
    second->data = 20;     
    second->next = third;
    third->data = 30;     
    third->next = NULL; 
    struct Node *current = head;
    printf("Linked list: ");
    while (current != NULL) 
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    free(head);
    free(second);
    free(third);
    return 0;
}
