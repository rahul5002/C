#include <stdio.h>  
#include <stdlib.h>  

struct Node 
{  
    char data;  
    struct Node* next;  
};  

struct Node* createNode(char data) 
{  
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  
    newNode->data = data;  
    newNode->next = NULL;  
    return newNode;  
}  

void push(struct Node** head_ref, char new_data) 
{  
    struct Node* new_node = createNode(new_data);  
    new_node->next = *head_ref;  
    *head_ref = new_node;  
}  

struct Node* reverse(struct Node* head) 
{  
    struct Node* prev = NULL;  
    struct Node* current = head;  
    struct Node* next = NULL;  

    while (current != NULL) 
    {  
        next = current->next;  
        current->next = prev;  
        prev = current;  
        current = next;  
    }  
    return prev;  
}  

int isPalindrome(struct Node* head) 
{  
    struct Node *slow = head, *fast = head;  
    struct Node *prev_of_slow = NULL;  

    while (fast != NULL && fast->next != NULL) 
    {  
        prev_of_slow = slow;  
        slow = slow->next;  
        fast = fast->next->next;  
    }  

    struct Node* second_half = slow;  
    if (fast != NULL) 
    {  
        second_half = slow->next;  
    }  

    second_half = reverse(second_half);  

    struct Node* first_half = head;  
    while (second_half != NULL) 
    {  
        if (first_half->data != second_half->data) 
        {  
            return 0;  
        }  
        first_half = first_half->next;  
        second_half = second_half->next;  
    }  

    if (prev_of_slow != NULL) 
    {  
        prev_of_slow->next = reverse(slow);  
    }  

    return 1;  
}  

void freeList(struct Node* head) 
{  
    struct Node* temp;  
    while (head) 
    {  
        temp = head;  
        head = head->next;  
        free(temp);  
    }  
}  

int main() 
{  
    struct Node* head = NULL;  

    push(&head, 'r');  
    push(&head, 'a');  
    push(&head, 'd');  
    push(&head, 'a');  
    push(&head, 'r');  

    if (isPalindrome(head)) 
    {  
        printf("The linked list is a palindrome.\n");  
    } 
    else 
    {  
        printf("The linked list is not a palindrome.\n");  
    }  

    freeList(head);  
    return 0;  
}