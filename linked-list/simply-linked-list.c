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
Node *insertAtPosition(Node *head, int value, int position);
Node *reverseList(Node *head);
void freeList(Node * head);
Node *reverseListV2(Node *head);
Node *findMiddle(Node *head);
Node *findMiddleV2(Node *head);
Node * insertAfterValue(Node* head, int value, int afterValue);
Node *insertBeforeValue(Node *head, int value, int beforeValue);

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

    printf("test inserting at position 2:\n");
    head = insertAtPosition(head,33,2);
    printList(head);

    printf("test inserting at position 0:\n");
    head = insertAtPosition(head,0,0);
    printList(head);

    printf("test inserting at position 6:\n");
    head = insertAtPosition(head,30,6);
    printList(head);

    printf("test inserting at position 8:\n");
    head = insertAtPosition(head,90,8);
    printList(head);

    printf("test deleteFirst:\n");
    head =  deleteFirst(head);
    printList(head);

    printf("test deleteLast:\n");
    head =  deleteLast(head);
    printList(head);

    printf("List reversed:\n");
    head = reverseListV2(head);
    printList(head);

    Node * midd = findMiddleV2(head);
    if (midd != NULL) {
        printf("the value of middle node is: %d\n", midd->value);
    } else {
        printf("list is empty\n");
    }

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

Node *insertAtPosition(Node *head, int value, int position) {

    if (position < 0) {
        printf("invalid position\n");
        return head;
    }

    if (position == 0) return PushFront(head, value);
    Node * p = head;
    int m = 0;
    while(m < position - 1  && p != NULL) {
        m++;
        p = p->next;
    }
    if (p == NULL) {
        printf("invalid position\n");
        return head;
    }
    Node * node = createNode(value);
    if (node == NULL) return head;
    node->next = p->next;
    p->next = node;
    return head;
}

Node *reverseList(Node *head) {
    if (head == NULL || head->next == NULL) return head;
    Node *p, *head2, *q;
    p = head;
    while(p->next != NULL) {
        q = p;
        p = p->next;
    }
    head2 = p;
    head2->next = q;
    while(true) {
        if (p == head) {
            p->next = NULL;
            break;
        }
        p = q;
        q = head;
        while(q->next != p && q != p) {
            q = q->next;
        }
        p->next = q;
    }
    return head2;
}

Node *reverseListV2(Node *head) {
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
    
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

Node *findMiddle(Node *head) {
    if (head == NULL) {
        printf("list is empty");
        return NULL;
    }

    int n = countNodes(head);
    int m = 0;
    Node * p = head;
    while (m < n/2)
    {
        p = p->next;
        m++;
    }
    return p;
    
}

Node *findMiddleV2(Node *head) {
    Node *fast = head,*slow=head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;

}

Node * insertAfterValue(Node* head, int value, int afterValue) {
    Node * p = head;

    while(p != NULL) {
        if (p->value == afterValue) {
            break;
        }
        p = p->next;
    }
    
    if (p == NULL) {
        printf("%d is not in the list\n", afterValue);
        return head;
    }
    Node* node = createNode(value);
    if (node == NULL) {
        return head;
    }
    node->next = p->next;
    p->next = node;
    return head;

}

Node *insertBeforeValue(Node *head, int value, int beforeValue){
    Node* current = head;
    Node* prev = NULL;

    while(current != NULL) {
        if (current->value == beforeValue) {
            break;
        }
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("the before value does not exists\n");
        return head;
    }
    Node * node = createNode(value);
    if (node == NULL) {
        return head;
    }
    node->next = current;
    if (head == current) {
        head = node;
    } else {
        prev->next = node;
    }
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