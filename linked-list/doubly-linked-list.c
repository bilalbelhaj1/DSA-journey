#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* next;
    struct Node*  prev;
} Node;

Node *createNode(int value);
void printForward(Node *head);
void printBackward(Node *tail);
void insertAtBeginning(Node **head, Node **tail, int value);

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    printf("Insert 3: ");
    insertAtBeginning(&head, &tail, 3);
    printForward(head);
    printf("Insert 2: ");
    insertAtBeginning(&head, &tail, 2);
    printForward(head);
    printf("Insert 1: ");
    insertAtBeginning(&head, &tail, 1);
    printForward(head);

    return 0;
}

Node *createNode(int value) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        printf("could not create a node\n");
        return NULL;
    }
    node->prev = NULL;
    node->next = NULL;
    node->value = value;
    return node;
}

void printForward(Node *head) {
    printf("NULL <==> ");
    while(head != NULL) {
        printf("%d <==> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

void printBackward(Node *tail) {
    printf("NULL <==> ");
    while(tail != NULL) {
        printf("%d <==> ", tail->value);
        tail = tail->prev;
    }
    printf("NULL\n");
}

void insertAtBeginning(Node **head, Node **tail, int value) {
    Node* node = createNode(value);
    if(node == NULL) {
        return;
    }
    if (*head == NULL) {
        *head = node;
        *tail = node;
    } else {
        node->next = *head;
        (*head)->prev = node;
        *head = node;
    }
}