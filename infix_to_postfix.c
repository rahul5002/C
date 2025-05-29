#include <stdio.h>
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
void infixToPostfix(char *infix, char *postfix) 
{
    Stack s;
    s.top = -1;
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) 
    {
        char ch = infix[i];
        if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) 
        {
            postfix[j++] = ch;
        } 
        else if (ch == '(') 
        {
            push(&s, ch);
        } 
        else if (ch == ')') 
        {
            while (s.top != -1 && peek(&s) != '(') 
            {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Remove '(' from stack
        } 
        else 
        {
            while (s.top != -1 && precedence(peek(&s)) >= precedence(ch)) 
            {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }
    
    while (s.top != -1) 
    {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}
int main() 
{
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
