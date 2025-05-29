#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct 
{
    char items[MAX];
    int top;
} Stack;

void push(Stack *s, char ch) 
{
    s->items[++(s->top)] = ch;
}

char pop(Stack *s) 
{
    return s->items[(s->top)--];
}

char peek(Stack *s) 
{
    return s->items[s->top];
}

int precedence(char op) 
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void reverseString(char *str) 
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) 
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void infixToPrefix(char *infix, char *prefix) 
{
    Stack s;
    s.top = -1;
    int j = 0;
    reverseString(infix);
    for (int i = 0; infix[i] != '\0'; i++) 
    {
        char ch = infix[i];
        if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) 
        {
            prefix[j++] = ch;
        } else if (ch == ')') 
        {
            push(&s, ch);
        } else if (ch == '(') 
        {
            while (s.top != -1 && peek(&s) != ')') 
            {
                prefix[j++] = pop(&s);
            }
            pop(&s);
        } 
        else 
        {
            while (s.top != -1 && precedence(peek(&s)) > precedence(ch)) 
            {
                prefix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }
    while (s.top != -1) 
    {
        prefix[j++] = pop(&s);
    }
    prefix[j] = '\0';
    reverseString(prefix);
}
int main() 
{
    char infix[MAX], prefix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}
