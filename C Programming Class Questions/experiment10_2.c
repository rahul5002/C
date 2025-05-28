/*Write a program to insert item in middle of the linked list.*/
#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node *next;
};
struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void displayList(struct Node* head) 
{
    struct Node* current = head;
    printf("Linked list: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void insertInMiddle(struct Node* head, int value, int position) 
{
    struct Node* newNode = createNode(value);
    struct Node* current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++) 
    {
        current = current->next;
    }
    if (current == NULL) 
    {
        printf("Position is invalid or out of bounds.\n");
        free(newNode);
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}
int main() 
{
    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);
    head->next = second;
    second->next = third;
    printf("Original ");
    displayList(head);
    int value = 15, position = 2;
    printf("Inserting %d at position %d...\n", value, position);
    insertInMiddle(head, value, position);
    printf("Updated ");
    displayList(head);
    struct Node* temp;
    while (head != NULL) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
