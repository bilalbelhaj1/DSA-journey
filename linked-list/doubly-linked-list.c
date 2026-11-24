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
void insertAtEnd(Node **head, Node **tail, int value);
void deleteFirst(Node **head, Node **tail);
void deleteLast(Node **head, Node **tail);
void insertAtPosition(Node **head, Node **tail, int value, int position);

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
    printf("Insert 4: ");
    insertAtEnd(&head, &tail, 4);
    printForward(head);

    printf("delete first: ");
    deleteFirst(&head, &tail);
    printForward(head);
    
    printf("delete Last: ");
    deleteLast(&head, &tail);
    printForward(head);

    printf("insert at position 0: ");
    insertAtPosition(&head, &tail, 1, 0);
    printForward(head);

    printf("insert at position 3: ");
    insertAtPosition(&head, &tail, 4, 3);
    printForward(head);

    printf("insert at position 2: ");
    insertAtPosition(&head, &tail, 40, 2);
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

void insertAtEnd(Node **head, Node **tail, int value) {
    Node* node = createNode(value);
    if (node == NULL) {
        return;
    }
    if(*head == NULL) {
        *head = node;
        *tail = node;
    } else {
        node->prev = *tail;
        (*tail) -> next = node;
        *tail = node;
    }
}

void deleteFirst(Node **head, Node **tail) {
    Node* tmp;
    if ((*head) == NULL) return;
    if ((*head)->next == NULL) {
        tmp = *head;
        *head = NULL;
        *tail = NULL;
        free(tmp);
        return;
    }
    tmp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(tmp);
}

void deleteLast(Node **head, Node **tail) {
    Node* tmp;
    if(*head == NULL) return;
    if ((*head) -> next == NULL) {
        tmp = *head;
        *head = NULL;
        *tail = NULL;
        free(tmp);
        return;
    }
    tmp = *tail;
    *tail = tmp->prev;
    (*tail) -> next = NULL;
    free(tmp);
}

void insertAtPosition(Node **head, Node **tail, int value, int position) {
    if (position < 0) {
        printf("Invalid position");
        return;
    }
    if (position == 0) {
        insertAtBeginning(head, tail, value);
        return;
    }
    Node* current = *head;

    int m = 0;
    while(m < position - 1 && current  != NULL) {
        m++;
        current = current->next;
    }
    if (current == NULL) {
        printf("invalid position\n");
        return;
    }

    if (current == *tail) {
        insertAtEnd(head, tail,value);
    } else {
        Node* node = createNode(value);
        node ->next = current->next;
        current -> next -> prev = node;
        current->next = node;
        node -> prev = current;
    }

}