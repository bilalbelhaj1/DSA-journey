#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Queue
{
    int data[MAX];
    int front;
    int rear;
} Queue;


void initQueue(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int peek(Queue *q);
void display(Queue *q);

int main() {
    Queue q;
    initQueue(&q);
    printf("Is empty: %d\n", isEmpty(&q));
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    display(&q);

    printf("Peek: %d\n", peek(&q));
    printf("dequeue: %d\n", dequeue(&q));
    printf("dequeue: %d\n", dequeue(&q));
    printf("dequeue: %d\n", dequeue(&q));

    display(&q);
    return  0;
}

void initQueue(Queue *q) {
    q -> front = -1;
    q -> rear = -1;
}

int isEmpty(Queue *q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

int isFull(Queue *q) {
    return q -> rear >=  MAX - 1;
}

void enqueue(Queue *q, int value) {
    if (isFull(q) == 1) {
        printf("Queue  is full\n");
        return;
    }
    if (isEmpty(q) == 1) {
        q -> front = 0;
    }
    q -> data[++q->rear] = value;
}

int dequeue(Queue *q) {
    if(isEmpty(q) == 1) {
        printf("the Queue is empty\n");
        exit(1);
    }
    if (q->front == q->rear) {
        int index = q->front;
        q->front = -1; q->rear = -1;
        return q->data[index];
    }
    return q -> data[q->front++];
}

int peek(Queue *q){
    if (isEmpty(q) == 1) {
        printf("The queue is empty\n");
        exit(1);
    }
    return q->data[q->front];
}

void display(Queue *q) {
    if(isEmpty(q) == 1) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q-> rear; i++ ) {
        printf("%d ", q-> data[i]);
    }
    printf("\n");
}