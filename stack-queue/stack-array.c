#include <stdio.h>
#include <stdlib.h>

#define MAX 10
typedef struct Stack
{
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s);

int isEmpty(Stack *s);

int isFull(Stack *s);

void push(Stack *s, int value);

int pop(Stack *s);

int peek(Stack *s);

void display(Stack *s);

int main() {
    Stack *s = malloc(sizeof(Stack));
    initStack(s);
}

void initStack(Stack *s) {
    s -> top = 0;
}

int isEmpty(Stack *s) {
    if (s -> top == 0) return 1;
    return 0;
}

int isFull(Stack *s) {
    if(s -> top < MAX) return 0;
    return 1;
}

void push(Stack *s, int value) {
    if (isFull(s) == 1) {
        printf("Stack is full cannot push to it\n");
        return;
    }
    s -> data[s->top++] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    return s -> data[-- s -> top];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    int index = s -> top - 1;
    return s -> data[index];
}

void display(Stack *s)  {
    if (isEmpty(s)) {
        printf("**** ");
        printf("*  * ");
        printf("**** ");
    } else {
        for (int i = s -> top - 1; i >= 0; i--) {
            printf("****** \n");
            printf("* %d * \n", s -> data[i]);
            printf("****** \n");
            printf("\n");
        }
    }
}