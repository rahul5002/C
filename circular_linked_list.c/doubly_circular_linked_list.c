#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct 
{
    Node* head;
} CircularList;

CircularList* createList() 
{
    CircularList* list = (CircularList*)malloc(sizeof(CircularList));
    list->head = NULL;
    return list;
}

void insertAtBeginning(CircularList* list, int value) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (list->head == NULL) 
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        list->head = newNode;
    } 
    else 
    {
        Node* last = list->head->prev;
        newNode->next = list->head;
        newNode->prev = last;
        list->head->prev = newNode;
        last->next = newNode;
        list->head = newNode;
    }
}

void insertAtEnd(CircularList* list, int value) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (list->head == NULL) 
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        list->head = newNode;
    } 
    else 
    {
        Node* last = list->head->prev;
        newNode->next = list->head;
        newNode->prev = last;
        list->head->prev = newNode;
        last->next = newNode;
    }
}

void deleteNode(CircularList* list, int value) 
{
    if (list->head == NULL) return;

    Node* current = list->head;
    Node* toDelete = NULL;

    do {
        if (current->data == value) 
        {
            toDelete = current;
            break;
        }
        current = current->next;
    } while (current != list->head);

    if (toDelete == NULL) return;

    if (toDelete->next == toDelete) 
    {
        list->head = NULL;
    } 
    else 
    {
        toDelete->prev->next = toDelete->next;
        toDelete->next->prev = toDelete->prev;

        if (toDelete == list->head) 
        {
            list->head = toDelete->next;
        }
    }

    free(toDelete);
}

void displayList(CircularList* list) 
{
    if (list->head == NULL) 
    {
        printf("List is empty\n");
        return;
    }

    Node* current = list->head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != list->head);
    printf("\n");
}

void freeList(CircularList* list) 
{
    if (list->head == NULL) return;

    Node* current = list->head;
    Node* temp;
    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != list->head);

    free(list);
}

int main() 
{
    CircularList* list = createList();

    insertAtEnd(list, 10);
    insertAtEnd(list, 20);
    insertAtBeginning(list, 5);
    insertAtEnd(list, 30);

    printf("List after insertions: ");
    displayList(list);

    deleteNode(list, 20);
    printf("List after deleting 20: ");
    displayList(list);

    freeList(list);
    return 0;
}