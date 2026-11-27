#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

typedef struct Queue
{
    int data[MAX];
    int rear;
    int front;
    int size;
} Queue;

typedef struct Node
{
    int value;
    struct Node* next;
} Node;

void  initQueue(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int isEmpty(Queue* q);
int isFull(Queue* q);
void pushFront(Node** head, int value);
void computeHeight(Node** tree, int root);

int main() {
    int n;
    scanf("%d", &n);

    int root = -1;

    Node** tree = malloc(n * sizeof(Node*));

    if (tree == NULL) {
        return EXIT_FAILURE;
    }

    for (int i = 0; i < n; i++) {
        tree[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        int parent;
        scanf("%d", &parent);

        if (parent == -1) {
            root = i;
        } else {
            pushFront(&tree[parent], i);
        }
    }

    if (root == -1) {
        free(tree);
        return EXIT_FAILURE;
    }

    computeHeight(tree, root);

    return 0;
}

void computeHeight(Node** tree, int root) {
    Queue q;
    initQueue(&q);
    Node* parent;
    int height = 0;
    enqueue(&q, root);
    while(isEmpty(&q) == 0) {
        int levelSize = q.size;
        for (int i = 0; i < levelSize; i++) {
            int tmp = dequeue(&q);
            parent = *(tree + tmp);
            while (parent != NULL) {
                enqueue(&q, parent->value);
                parent = parent->next;
            }
        }

        height++;
    }
    printf("%d\n", height);
}

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

void pushFront(Node** head, int value) {
    Node* node = malloc(sizeof(Node));
    node->value = value;
    node->next = *head;
    *head = node;
}

int isFull(Queue* q) {
    return q->size == MAX;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) return;
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
    q->size++;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) exit(EXIT_FAILURE);

    int value = q->data[q->front];

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }

    q->size--;

    return value;
}