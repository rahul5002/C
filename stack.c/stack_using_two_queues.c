
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

typedef struct {
    Queue q1;
    Queue q2;
} Stack;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

void initStack(Stack* s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
}

int isQueueEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    
    if (q->front == -1) {
        q->front = 0;
    }
    
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    
    int item = q->items[q->front];
    
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    
    return item;
}

void push(Stack* s, int value) {
    enqueue(&s->q1, value);
}

int pop(Stack* s) {
    if (isQueueEmpty(&s->q1)) {
        printf("Stack is empty\n");
        return -1;
    }
    
    while (s->q1.front != s->q1.rear) {
        enqueue(&s->q2, dequeue(&s->q1));
    }
    
    int topItem = dequeue(&s->q1);
    
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
    
    initQueue(&s->q2);
    
    return topItem;
}

int main() {
    Stack s;
    initStack(&s);
    
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    
    return 0;
}