#include <stdio.h>  
#include <stdlib.h>  

typedef struct Node 
{  
    int data;  
    struct Node* next;  
} Node;  

typedef struct Stack 
{  
    Node* top;  
} Stack;  

Node* createNode(int value) 
{  
    Node* newNode = (Node*)malloc(sizeof(Node));  
    if (!newNode) 
    {  
        printf("Memory allocation failed\n");  
        exit(EXIT_FAILURE);  
    }  
    newNode->data = value;  
    newNode->next = NULL;  
    return newNode;  
}  

Stack* createStack() 
{  
    Stack* stack = (Stack*)malloc(sizeof(Stack));  
    if (!stack) 
    {  
        printf("Memory allocation failed\n");  
        exit(EXIT_FAILURE);  
    }  
    stack->top = NULL;  
    return stack;  
}  

void push(Stack* stack, int value) 
{  
    Node* newNode = createNode(value);  
    newNode->next = stack->top;  
    stack->top = newNode;  
    printf("Pushed %d onto the stack.\n", value);  
}  

void pop(Stack* stack) 
{  
    if (stack->top == NULL) 
    {  
        printf("Stack Underflow\n");  
        return;  
    }  
    Node* temp = stack->top;  
    printf("Popped value: %d\n", temp->data);  
    stack->top = stack->top->next;  
    free(temp);  
}  

void display(Stack* stack) 
{  
    if (stack->top == NULL) 
    {  
        printf("Stack is empty\n");  
        return;  
    }  
    Node* current = stack->top;  
    printf("The elements in the stack are: ");  
    while (current != NULL) 
    {  
        printf("%d ", current->data);  
        current = current->next;  
    }  
    printf("\n");  
}  

int main() 
{  
    Stack* stack = createStack();  
    int choice, value;  
    while (1) 
    {  
        printf("Stack Operations\n");  
        printf("1. Push\n");  
        printf("2. Pop\n");  
        printf("3. Display\n");  
        printf("4. Exit\n");  
        printf("Enter your choice: ");  
        scanf("%d", &choice);  
        switch (choice) 
        {  
            case 1:  
                printf("Enter value to push: ");  
                scanf("%d", &value);  
                push(stack, value);  
                break;  
            case 2:  
                pop(stack);  
                break;  
            case 3:  
                display(stack);  
                break;  
            case 4:  
                while (stack->top != NULL) 
                {  
                    pop(stack);  
                }  
                free(stack);  
                exit(0);  
            default:  
                printf("Invalid choice\n");  
        }  
    }  
    return 0;  
}