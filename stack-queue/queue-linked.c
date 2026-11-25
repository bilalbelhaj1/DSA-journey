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