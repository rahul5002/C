#include <stdio.h>
#include <stdlib.h>

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
    printf("\n");
}

void loop_detection(struct node *head)
{
    struct node *slow = head;
    struct node *fast = head;

    if (head == NULL)
    {
        printf("Empty list.\n");
        return;
    }

    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            printf("Loop detected.\n");
            return;
        }
    }
    printf("No loop detected.\n");
}

int main() 
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 5;
    head->next = second;
    second->data = 9;
    second->next = third;
    third->data = 15;
    third->next = fourth;
    fourth->data = 20;
    fourth->next = second;

    printf("Original linked list:\n");
    linked_list_traverse(head);
    loop_detection(head);

    struct node *temp;
    while (head != NULL && head != second) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
