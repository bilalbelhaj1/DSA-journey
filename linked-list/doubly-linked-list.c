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
void deleteAtPosition(Node **head, Node **tail, int position);
void reverseList(Node **head, Node **tail);
void removeDuplicates(Node **head, Node **tail);

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtBeginning(&head, &tail, 3);
    insertAtBeginning(&head, &tail, 40);
    insertAtBeginning(&head, &tail, 1);
    insertAtEnd(&head, &tail, 1);
    insertAtPosition(&head, &tail, 1, 0);
    insertAtPosition(&head, &tail, 1, 3);
    insertAtPosition(&head, &tail, 40, 2);
    insertAtPosition(&head, &tail, 40, 2);
    insertAtPosition(&head, &tail, 3, 2);
    insertAtPosition(&head, &tail, 40, 2);
    insertAtPosition(&head, &tail, 1, 2);
    insertAtPosition(&head, &tail, 40, 2);

    printf("List reversed: ");
    reverseList(&head, &tail);
    printForward(head);

    printf("Delete duplicates: ");
    removeDuplicates(&head, &tail);
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
    return;
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
        if(node == NULL) {
            printf("failled to create a node\n");
            return;
        }
        node ->next = current->next;
        current -> next -> prev = node;
        current->next = node;
        node -> prev = current;
    }

}

void deleteAtPosition(Node **head, Node **tail, int position) {
    if (*head == NULL) {
        printf("list is empty\n");
        return;
    }
    if (position < 0) {
        printf("invalid position\n");
        return;
    }

    if (position == 0) {
        deleteFirst(head, tail); return;
    }

    int m = 0;
    Node* p = *head;
    while(m < position &&  p != NULL) {
        m++;
        p = p->next;
    }

    if (p == NULL) {
        printf("invalid position\n");
        return;
    }

    if (*tail == p) {
        deleteLast(head,tail); return;
    }

    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
}

void reverseList(Node **head, Node **tail) {
    if (*head == NULL) {
        return;
    }
    Node* tmp, *current = *head;
    while(current != NULL) {
        tmp = current -> next;
        current -> next = current -> prev;
        current -> prev = tmp;
        current = tmp;
    }
    tmp = *head;
    *head = *tail;
    *tail = tmp;
}

void removeDuplicates(Node **head, Node **tail) {
    if(*head == NULL || (*head) -> next == NULL) return;
    Node* current = *head;
    Node* tmp;
    Node* tmp2;
    while (current != NULL) 
    {
        tmp = current->next;
        while(tmp != NULL) {
            if(tmp->value == current->value) {
                if(tmp == *tail) {
                    deleteLast(head, tail);
                    break;
                }
                tmp2 = tmp;
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                tmp = tmp->next;
                free(tmp2);
            } else {
                tmp = tmp->next;
            }
        }   
        current = current -> next;
    }
    
}