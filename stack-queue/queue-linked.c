#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

typedef struct Queue
{
    Node* front;
    Node* rear;
}Queue;

void initQueue(Queue* q);

int isEmpty(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int peek(Queue *q);

void display(Queue *q);
void freeQueue(Queue *q);

int main() {
    Queue q;
    initQueue(&q);

    // Test 1: Empty queue
    printf("Is empty? %d\n", isEmpty(&q));

    // Test 2: Enqueue elements
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(&q);
    printf("\n");

    // Test 3: Peek
    printf("Front element: %d\n", peek(&q));

    // Test 4: Dequeue
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    display(&q);
    printf("\n");

    // Test 5: Dequeue remaining elements
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    // Test 6: Check empty queue
    printf("Is empty? %d\n", isEmpty(&q));
    display(&q);

    // Test 7: Reuse queue after emptying it
    enqueue(&q, 100);
    enqueue(&q, 200);

    display(&q);
    printf("\n");

    // Test 8: Free memory
    freeQueue(&q);

    printf("Memory freed successfully.\n");

    return 0;
}

void initQueue(Queue* q) {
    q -> front = NULL;
    q -> rear = NULL;
}

int isEmpty(Queue *q) {
    return  q -> front == NULL;
}

void enqueue(Queue *q, int value) {
    Node* node = malloc(sizeof(Node));
    if (node  == NULL) {
        printf("failled\n");
        return;
    }
    node->data = value;
    node->next = NULL;
    if (q->front ==  NULL) {
        q->front = node;
        q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }
}
int dequeue(Queue *q){
    if (isEmpty(q) == 1) {
        printf("Queue is empty\n");
        exit(1);
    }
    Node* tmp = q->front;
    q->front = tmp->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    int dequeued = tmp->data;
    free(tmp);
    return dequeued;
}
int peek(Queue *q)  {
    if (isEmpty(q) == 1) {
        printf("The queue is empty\n");
        exit(1);
    }
    return q->front->data;
}

void display(Queue *q) {
    if (isEmpty(q) == 1) {
        printf("the Queue is empty\n");
        return;
    }
    Node* p =  q->front;
    printf("Front: ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf(" rear");

    
}
void freeQueue(Queue *q) {
    Node* tmp = q->front;
    Node* next;
    while (tmp != NULL)
    {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    q->front = NULL;
    q->rear = NULL;
}