#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

int max(int a, int b);
Node* createNode(int value);
int isEmpty(Node* root);
int countNodes(Node* root);
int findHeight(Node* root);
void freeTree(Node* root);
void inOrder(Node* root);
void preOrder(Node* root);
void postOrder(Node* root);

int main() {
    Node* root = createNode(5);
    Node* leftNode, *rightNode;
    leftNode = createNode(6);
    rightNode = createNode(9);

    root->left = leftNode;
    root->right = rightNode;

    leftNode = createNode(7);
    rightNode = createNode(8);

    root->left->left = leftNode;
    root->left->right = rightNode;

    rightNode = createNode(10);
    root->right->right = rightNode;
    printf("Is empty: %d\n", isEmpty(root));
    printf("number of nodes: %d\n", countNodes(root));
    printf("Height of the tree: %d\n", findHeight(root));

    printf("In order: ");
    inOrder(root);
    printf("\n");

    printf("PreOrder: ");
    preOrder(root);
    printf("\n");

    printf("Post Order: ");
    postOrder(root);
    printf("\n");

    freeTree(root);
    return 0;
}

Node* createNode(int value) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        printf("failled to create Node\n");
        return NULL;
    }
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int isEmpty(Node* root) {
    return root == NULL;
}
int countNodes(Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int max(int a, int b) {
    return a > b ? a : b;
}

int findHeight(Node* root) {
    if (root == NULL) {
        return 0;
    } 
    return 1 + max(findHeight(root->left), findHeight(root->right));
}

void freeTree(Node* root) {
    if (root== NULL) return;
    if (root->left == NULL && root->right == NULL) {
        printf("release %d\n", root->data);
        free(root);
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    printf("release %d\n", root->data);
    free(root);
}

void inOrder(Node* root) {
    if (root == NULL) return;

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}
void preOrder(Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node* root) {
    if (root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}