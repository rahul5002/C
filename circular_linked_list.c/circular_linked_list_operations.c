#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linked_list_traverse(struct node *head)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    struct node *ptr = head;
    do
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("HEAD\n");
}

void insert_at_last(struct node **head, int value)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;

    if (*head == NULL)
    {
        new_node->next = new_node;
        *head = new_node;
        return;
    }

    struct node *temp = *head;
    while (temp->next != *head)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = *head;
}

void insert_at_beginning(struct node **head, int value)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;

    if (*head == NULL)
    {
        new_node->next = new_node;
        *head = new_node;
        return;
    }

    struct node *temp = *head;
    while (temp->next != *head)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = *head;
    *head = new_node;
}

void insert_at_position(struct node **head, int value, int position)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;

    if (position == 1)
    {
        insert_at_beginning(head, value);
        return;
    }

    struct node *temp = *head;
    for (int i = 1; i < position - 1 && temp->next != *head; i++)
    {
        temp = temp->next;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

void delete_at_beginning(struct node **head)
{
    if (*head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    struct node *temp = *head;

    while (temp->next != *head)
    {
        temp = temp->next;
    }

    struct node *to_delete = *head;
    if (temp == *head)
    {
        *head = NULL;
    }
    else
    {
        temp->next = (*head)->next;
        *head = (*head)->next;
    }
    free(to_delete);
}

void delete_at_last(struct node **head)
{
    if (*head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    struct node *temp = *head;
    struct node *prev;

    while (temp->next != *head)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == *head)
    {
        *head = NULL;
    }
    else
    {
        prev->next = *head;
    }
    free(temp);
}

void delete_at_position(struct node **head, int position)
{
    if (*head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    if (position == 1)
    {
        delete_at_beginning(head);
        return;
    }

    struct node *temp = *head;
    struct node *prev;

    for (int i = 1; i < position && temp->next != *head; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == *head)
    {
        printf("Invalid position.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int main()
{
    struct node *head = NULL;

    insert_at_last(&head, 10);
    insert_at_last(&head, 20);
    insert_at_last(&head, 30);
    insert_at_beginning(&head, 5);
    insert_at_position(&head, 25, 3);

    linked_list_traverse(head);

    delete_at_beginning(&head);
    linked_list_traverse(head);

    delete_at_last(&head);
    linked_list_traverse(head);

    delete_at_position(&head, 2);
    linked_list_traverse(head);

    return 0;
}