#include <stdio.h>  
#include <stdlib.h>  
#include <stdbool.h>  

typedef struct 
{  
    int *stack1;  
    int *stack2;  
    int top1;  
    int top2;  
    int maxSize;  
} TwoArrayStack;  

void initStack(TwoArrayStack* s, int size) 
{  
    s->maxSize = size;  
    s->stack1 = (int *)malloc(size * sizeof(int));  
    s->stack2 = (int *)malloc(size * sizeof(int));  
    s->top1 = -1;  
    s->top2 = -1;  
}  

void freeStack(TwoArrayStack* s) 
{  
    free(s->stack1);  
    free(s->stack2);  
}  

bool isEmpty(TwoArrayStack* s) 
{  
    return (s->top1 == -1 && s->top2 == -1);  
}  

void push(TwoArrayStack* s, int value) 
{  
    if (s->top1 < s->maxSize - 1) 
    {  
        s->stack1[++s->top1] = value;  
        printf("Value %d pushed onto the stack.\n", value);  
    } 
    else 
    {  
        printf("Stack overflow! Cannot push more elements.\n");  
    }  
}  

int pop(TwoArrayStack* s) 
{  
    if (isEmpty(s)) 
    {  
        printf("Stack underflow! Cannot pop from an empty stack.\n");  
        exit(EXIT_FAILURE);  
    }  

    if (s->top2 == -1) 
    {  
        while (s->top1 != -1) 
        {  
            s->stack2[++s->top2] = s->stack1[s->top1--];  
        }  
    }  

    return s->stack2[s->top2--];  
}  

void topTwo(TwoArrayStack* s) 
{  
    if (isEmpty(s)) 
    {  
        printf("Stack is empty! No top elements to show.\n");  
        return;  
    }  

    if (s->top2 != -1) 
    {  
        printf("Top two elements are: %d and %d\n", s->stack2[s->top2], s->top2 > 0 ? s->stack2[s->top2 - 1] : -1);  
    } 
    else 
    {  
        if (s->top1 >= 1) 
        {  
            printf("Top two elements are: %d and %d\n", s->stack1[s->top1], s->stack1[s->top1 - 1]);  
        } else if (s->top1 == 0) 
        {  
            printf("Top one element is: %d\n", s->stack1[s->top1]);  
        } 
        else 
        {  
            printf("Stack has no elements.\n");  
        }  
    }  
}  

int main() 
{  
    int maxSize;  
    printf("Enter the maximum size of the stack: ");  
    scanf("%d", &maxSize);  

    TwoArrayStack stack;  
    initStack(&stack, maxSize);  

    while (true) 
    {  
        int choice;  
        printf("\nMenu:\n");  
        printf("1. Push\n");  
        printf("2. Pop\n");  
        printf("3. View Top Two Elements\n");  
        printf("4. Exit\n");  
        printf("Choose an option: ");  
        scanf("%d", &choice);  

        switch (choice) 
        {  
            case 1:  
                {  
                    int value;  
                    printf("Enter value to push: ");  
                    scanf("%d", &value);  
                    push(&stack, value);  
                }  
                break;  
            case 2:  
                {  
                    if (!isEmpty(&stack)) 
                    {  
                        printf("Popped: %d\n", pop(&stack));  
                    }  
                }  
                break;  
            case 3:  
                topTwo(&stack);  
                break;  
            case 4:  
                freeStack(&stack);  
                return 0;  
            default:  
                printf("Invalid option, please try again.\n");  
        }  
    }  
}