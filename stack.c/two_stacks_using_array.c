#include <stdio.h>
#include <stdlib.h>

struct TwoStacks 
{
    int* arr;
    int size;
    int top1, top2;
};

struct TwoStacks* createTwoStacks(int n) 
{
    struct TwoStacks* ts = (struct TwoStacks*)malloc(sizeof(struct TwoStacks));
    ts->size = n;
    ts->arr = (int*)malloc(n * sizeof(int));
    ts->top1 = -1;
    ts->top2 = n;
    return ts;
}

void push1(struct TwoStacks* ts, int x) 
{
    if (ts->top1 < ts->top2 - 1) 
    {
        ts->arr[++ts->top1] = x;
    } 
    else 
    {
        printf("Stack Overflow in Stack 1\n");
    }
}

void push2(struct TwoStacks* ts, int x) 
{
    if (ts->top1 < ts->top2 - 1) 
    {
        ts->arr[--ts->top2] = x;
    } 
    else 
    {
        printf("Stack Overflow in Stack 2\n");
    }
}

int pop1(struct TwoStacks* ts) 
{
    if (ts->top1 >= 0) 
    {
        return ts->arr[ts->top1--];
    } 
    else 
    {
        printf("Stack Underflow in Stack 1\n");
        return -1;
    }
}

int pop2(struct TwoStacks* ts) 
{
    if (ts->top2 < ts->size) 
    {
        return ts->arr[ts->top2++];
    } 
    else 
    {
        printf("Stack Underflow in Stack 2\n");
        return -1;
    }
}

void freeTwoStacks(struct TwoStacks* ts) 
{
    free(ts->arr);
    free(ts);
}

int main() 
{
    struct TwoStacks* ts = createTwoStacks(10);

    push1(ts, 5);
    push1(ts, 10);
    push2(ts, 15);
    push2(ts, 20);

    printf("Popped from Stack 1: %d\n", pop1(ts));
    printf("Popped from Stack 2: %d\n", pop2(ts));

    freeTwoStacks(ts);
    return 0;
}