#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* createNode(int data) 
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

int maxNodeData(struct node* head)
{
    if (head == NULL) 
    {
        printf("List is empty.\n");
        return -1;
    }
    int max = head->data;
    struct node* temp = head;
    while (temp != NULL) 
    {
        if (temp->data > max) 
        {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

int minNodeData(struct node* head)
{
    if (head == NULL) 
    {
        printf("List is empty.\n");
        return -1;
    }
    int min = head->data;
    struct node* temp = head;
    while (temp != NULL) 
    {
        if (temp->data < min) 
        {
            min = temp->data;
        }
        temp = temp->next;
    }
    return min;
}

void insertAtBeginning(struct node** head, int data) 
{
    struct node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insertAtEnd(struct node** head, int data) 
{
    struct node* newNode = createNode(data);
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    struct node* temp = *head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode(struct node** head, int data) 
{
    struct node* temp = *head;
    if (temp == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    
    while (temp != NULL && temp->data != data) 
    {
        temp = temp->next;
    }

    if (temp == NULL) 
    {
        printf("Node with data %d not found.\n", data);
        return;
    }

    if (temp == *head) 
    {
        *head = temp->next;
        if (*head != NULL) 
        {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    if (temp->prev != NULL) 
    {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) 
    {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

void displayList(struct node* head) 
{
    struct node* temp = head;
    if (temp == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) 
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void nodeCount(struct node* head) 
{
    struct node* temp = head;
    int count = 0;
    if (temp == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) 
    {
        count++;
        temp = temp->next;
    }
    printf("Number of nodes in the list is %d\n", count);
}

void displayListReverse(struct node* head) 
{
    struct node* temp = head;
    if (temp == NULL) 
    {
        printf("List is empty.\n");
        return;
    }

    while (temp->next != NULL) 
    {
        temp = temp->next;
    }

    while (temp != NULL) 
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

void insertionAtAnyGivenNode(struct node** head, int data, int pos) 
{
    struct node* newNode = createNode(data);
    struct node* temp = *head;
    for (int i = 1; i < pos && temp != NULL; i++) 
    {
        temp = temp->next;
    }
    if (temp != NULL) 
    {
        newNode->next = temp->next;
        if (temp->next != NULL) 
        {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    else 
    {
        printf("Position out of range\n");
        free(newNode);
    }
}

void deleteAtBeginning(struct node** head) 
{
    if (*head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) 
    {
        (*head)->prev = NULL;
    }
    free(temp);
}

void deleteAtEnd(struct node** head) 
{
    if (*head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = *head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    if (temp->prev != NULL) 
    {
        temp->prev->next = NULL;
    }
    else 
    {
        *head = NULL;
    }
    free(temp);
}

void deleteAtAnyGivenNode(struct node** head, int data) 
{
    deleteNode(head, data);
}

int main() 
{
    struct node* head = NULL;
    int choice, value, pos;
    while (1) 
    {
        printf("Enter the operation you want to perform:\n1. Display list\n2. Insert at Beginning\n3. Insert at any given node\n4. Insertion at End\n5. Delete at Beginning\n6. Delete at any given node\n7. Delete at End\n8. Display list in reverse order\n9. Count the no. of nodes\n10.Maximum Data Value\n11.Minimum Data Value\n12. Exit\n");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Doubly Linked List (Forward): ");
                displayList(head);
                break;
            case 2:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                printf("After inserting node:\n");
                displayList(head);
                break;
            case 3:
                printf("Enter value and position to insert: ");
                scanf("%d %d", &value, &pos);
                insertionAtAnyGivenNode(&head, value, pos);
                printf("After inserting node:\n");
                displayList(head);
                break;
            case 4:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                printf("After inserting node:\n");
                displayList(head);
                break;
            case 5:
                deleteAtBeginning(&head);
                printf("After deleting node:\n");
                displayList(head);
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteAtAnyGivenNode(&head, value);
                printf("After deleting node:\n");
                displayList(head);
                break;
            case 7:
                deleteAtEnd(&head);
                printf("After deleting node:\n");
                displayList(head);
                break;
            case 8:
                printf("Doubly Linked List (Reverse): ");
                displayListReverse(head);
                break;
            case 9:
                nodeCount(head);
                break;
            case 10:
                printf("The Maximum Data Value is: %d\n", maxNodeData(head));
                break;
            case 11:
                printf("The Minimum Data Value is: %d\n", minNodeData(head));
                break;
            case 12:
                exit(0);
                break;
            default:
                printf("Invalid Input, Try Again!\n");
        }
    }
    return 0;
}
