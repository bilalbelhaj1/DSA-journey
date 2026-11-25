#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* createNode(int value);

void push(Node **top, int value);

int pop(Node **top);

int peek(Node *top);

int isEmpty(Node *top);

void display(Node *top);

void freeStack(Node **top);

int size(Node *top);

int main() {
    Node* top = NULL;
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    push(&top, 40);
    display(top);
    printf("%d\n", pop(&top));

    display(top);
    printf("%d\n", peek(top));
    printf("is empty: %d\n", isEmpty(top));
    display(top);

    printf("Size of the stack: %d\n", size(top));

    freeStack(&top);

    return 0;
}

Node* createNode(int value) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        printf("failled\n");
        exit(1);
    }
    node -> next = NULL;
    node -> data = value;
    return node;
}

void push(Node **top, int value) {
    Node* node = createNode(value);

    node->next = *top;
    *top = node;
}

int pop(Node **top) {
    if (*top == NULL) {
        printf("Stack empty\n");
        exit(1);
    }

    Node* tmp = *top;
    int poped = tmp -> data;
    *top = tmp -> next;
    free(tmp);
    return poped;
}

int peek(Node *top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        exit(1);
    }
    return top -> data;
}

int isEmpty(Node *top) {
    return top == NULL;
}

void display(Node *top) {
    while(top != NULL) {
        printf("%d\n", top -> data);
        top = top -> next;
    }
}

void freeStack(Node **top) {
    Node* next ;
    while(*top != NULL) {
        next = (*top) -> next;
        free(*top);
        *top = next;
    }
}

int size(Node *top) {
    if (isEmpty(top) == 1) return 0;
    int counter = 0;
    while (top != NULL)
    {
        counter++;
        top = top -> next;
    }
    return counter;
    
}