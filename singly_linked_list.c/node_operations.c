#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

void linked_list_traverse(struct node *ptr) 
{
    if (ptr == NULL) 
    {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (ptr != NULL) 
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void linked_list_reversal(struct node **head)
{
    struct node *prev=NULL;
    struct node *current=*head;
    struct node *temp=NULL;
    while(current!=NULL)
    {
        temp=current->next;
        current->next=prev;
        prev=current;
        current=temp;
    }
    *head=prev;
}
void insert_at_beginning(struct node **head, int value) 
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
    printf("%d inserted at the beginning.\n", value);
}

void insert_after_position(struct node **head, int position, int value) 
{
    struct node *temp = *head;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;

    for (int i = 0; temp != NULL && i < position; i++) 
    {
        temp = temp->next;
    }

    if (temp == NULL) 
    {
        printf("Position out of range.\n");
        free(new_node);
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    printf("%d inserted after position %d.\n", value, position);
}

void deletion_before_any_node(struct node **head, int position) 
{
    if (*head == NULL || position <= 1)  // Corrected
    {
        printf("Deletion before this position is not possible.\n");
        return;
    }

    if (position == 2) 
    {
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Node before position %d deleted.\n", position);
        return;
    }

    struct node *prev = NULL;
    struct node *temp = *head;

    for (int i = 0; temp != NULL && i < position-2; i++) 
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) 
    {
        printf("Position out of range.\n");
        return;
    }

    prev = temp->next;
    temp->next = prev->next;
    free(prev);

    printf("Node before position %d deleted.\n", position);
}

int main() 
{
    struct node *head = NULL;
    int choice, value, position;

    while (1) 
    {
        printf("\nChoose an operation:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert after a position\n");
        printf("3. Delete before a position\n");
        printf("4. Display list\n");
        printf("5. Reverse linked list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter value to insert at the beginning: ");
                scanf("%d", &value);
                insert_at_beginning(&head, value);
                break;

            case 2:
                printf("Enter position after which to insert: ");
                scanf("%d", &position);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert_after_position(&head, position, value);
                break;

            case 3:
                printf("Enter position before which to delete: ");
                scanf("%d", &position);
                deletion_before_any_node(&head, position);
                break;

            case 4:
                linked_list_traverse(head);
                break;

            case 5:
                linked_list_reversal(&head);
                break;

            case 6:
                printf("Exiting...\n");
                while (head != NULL) 
                {
                    struct node *temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

