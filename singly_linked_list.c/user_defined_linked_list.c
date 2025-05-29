#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};
void insertAtBeginning(struct Node** head, int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}
void insertAtEnd(struct Node** head, int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }

    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertAfterNode(struct Node* prev_node, int value) 
{
    if (prev_node == NULL) 
    {
        printf("The given previous node cannot be NULL.\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = prev_node->next;
    prev_node->next = newNode;
}
void deleteNode(struct Node** head, struct Node* target) 
{
    if (*head == NULL || target == NULL) 
    {
        printf("Invalid operation: List is empty or target node is NULL.\n");
        return;
    }

    if (*head == target) 
    { 
        *head = target->next;
        free(target);
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL && temp->next != target) 
    {
        temp = temp->next;
    }

    if (temp->next == NULL) 
    {
        printf("Node not found in the list.\n");
        return;
    }

    temp->next = target->next;
    free(target);
}
void displayList(struct Node* node) 
{
    if (node == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (node != NULL) 
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}
struct Node* getNodeByPosition(struct Node* head, int position) 
{
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) 
    {
        if (count == position)
            return temp;
        temp = temp->next;
        count++;
    }
    return NULL;
}
int main() 
{
    struct Node* head = NULL;
    int choice, value, pos;
    struct Node* selectedNode;

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after a node (by position)\n");
        printf("4. Delete a node (by position)\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter value to insert at the beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;

            case 2:
                printf("Enter value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;

            case 3:
                printf("Enter position of the node after which to insert: ");
                scanf("%d", &pos);
                selectedNode = getNodeByPosition(head, pos);
                if (selectedNode == NULL) 
                {
                    printf("Invalid position! No node found.\n");
                } 
                else 
                {
                    printf("Enter value to insert: ");
                    scanf("%d", &value);
                    insertAfterNode(selectedNode, value);
                }
                break;

            case 4:
                printf("Enter position of the node to delete: ");
                scanf("%d", &pos);
                selectedNode = getNodeByPosition(head, pos);
                if (selectedNode == NULL) 
                {
                    printf("Invalid position! No node found.\n");
                } 
                else 
                {
                    deleteNode(&head, selectedNode);
                }
                break;

            case 5:
                displayList(head);
                break;

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
