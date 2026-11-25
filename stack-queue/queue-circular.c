#include <stdio.h>

#define MAX 10

typedef struct Queue
{
    int data[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q);
int isFull(Queue* q);
int isEmpty(Queue* q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int peek(Queue *q);
void display(Queue *q);

int main() {
    Queue q;
    initQueue(&q);

    printf("========== TEST 1: BASIC OPERATIONS ==========\n");

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printf("Queue: ");
    display(&q);

    printf("Peek: %d\n", peek(&q));

    printf("Dequeue: %d\n", dequeue(&q));
    printf("Dequeue: %d\n", dequeue(&q));

    printf("Queue after dequeue: ");
    display(&q);


    printf("\n========== TEST 2: CIRCULAR WRAPPING ==========\n");

    enqueue(&q, 50);
    enqueue(&q, 60);
    enqueue(&q, 70);
    enqueue(&q, 80);
    enqueue(&q, 90);
    enqueue(&q, 100);
    enqueue(&q, 110);
    enqueue(&q, 120);

    printf("Queue after inserting more elements: ");
    display(&q);

    printf("Front element: %d\n", peek(&q));


    printf("\n========== TEST 3: FULL QUEUE ==========\n");

    enqueue(&q, 130);

    printf("Queue: ");
    display(&q);


    printf("\n========== TEST 4: EMPTY QUEUE ==========\n");

    while (!isEmpty(&q)) {
        printf("Removed: %d\n", dequeue(&q));
    }

    display(&q);

    printf("Is empty: %d\n", isEmpty(&q));


    printf("\n========== TEST 5: REUSE EMPTY QUEUE ==========\n");

    enqueue(&q, 500);
    enqueue(&q, 600);

    display(&q);

    printf("Peek: %d\n", peek(&q));

    return 0;
}

int isFull(Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}
int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue *q, int value) {
    if (isFull(q) == 1) {
        printf("Queue  is full\n");
        return;
    }
    if (isEmpty(q) == 1) {
        q -> front = 0;
    }
    q -> rear = (q->rear + 1) % MAX;
    q -> data[q->rear] = value;
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
    int todequeue = q->front;
    q->front = (q->front + 1) % MAX;
    return q -> data[todequeue];
}

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int peek(Queue *q) {
    if (isEmpty(q) == 1) {
        printf("The queue is empty\n");
        exit(1);
    }
    return q->data[q->front];
}

void display(Queue* q) {

    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    int i = q->front;

    while (1) {
        printf("%d ", q->data[i]);

        if (i == q->rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}