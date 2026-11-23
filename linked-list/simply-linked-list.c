#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node * next;
} Node;

Node * createNode(int value) ;
Node * PushFront(Node * head, int value);
Node * PushBack(Node * head, int value);
void printList(Node * head);
int countNodes(Node * head);
bool searchNode(Node * head, int value);
Node * deleteFirst(Node * head);
Node *  deleteLast(Node * head);
void freeList(Node * head);

int main() {
    Node * head = NULL;
    head = PushFront(head,3);
    head = PushFront(head,2);
    head = PushFront(head,1);
    head = PushBack(head, 4);
    head = PushBack(head, 5);
    printf("List size is : %d\n", countNodes(head));
    printf("does the value %d exists: %d\n", 8, searchNode(head, 8));
    printf("does the value %d exists: %d\n", 4, searchNode(head, 4));
    printf("the list values: \n");
    printList(head);

    printf("test deleteFirst:\n");
    head =  deleteFirst(head);
    printList(head);

    printf("test deleteLast:\n");
    head =  deleteLast(head);
    printList(head);

    free(head);
    return 0;
}

Node * createNode(int value) {
    Node * n = malloc(sizeof(Node));
    if (n == NULL) {
        printf("failled to create a node\n");
        return NULL;
    }
    n->value = value;
    n->next = NULL;
    return n;
}

Node * PushFront(Node * head, int value) {
    Node * n = createNode(value);
    if  (head == NULL) {
        head = n;
    } else {
        n->next = head;
        head = n;
    }
    return head;
}

Node * PushBack(Node * head, int value) {
    Node * n = createNode(value);
    if (head == NULL) return n;

    Node * p = head;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = n;

    return head;
}

void printList(Node * head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        printf("HEAD => ");
        Node * p = head;
        while(p != NULL) {
            printf("%d => ", p->value);
            p = p->next;
        }
        printf("NULL");
    }
    printf("\n");
}

int countNodes(Node * head) {
    Node * p = head;
    int counter = 0;
    while (p != NULL) {
        counter++;
        p = p->next;
    }
    return counter;
}

bool searchNode(Node * head, int value) {
    if (head == NULL) return false;
    Node * p = head;
    while(p != NULL) {
        if (p->value == value) return true;
        p = p->next;
    }
    return false;
}

Node * deleteFirst(Node * head) {
    if (head == NULL) {
        printf("Nothing to delte\n");
        return head;
    }
    Node * tmp = head;
    head = head->next;
    free(tmp);
    return head;
}

Node *  deleteLast(Node * head) {
    if (head == NULL || head->next == NULL) return deleteFirst(head);

    Node *p, *tmp;
    p = head;

    while(p->next->next != NULL) {
        p = p->next;
    }
    tmp = p->next;
    p->next = NULL;
    free(tmp);
    return head;
}

void freeList(Node * head) {
    Node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}