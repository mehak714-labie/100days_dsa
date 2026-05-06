#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Queue {
    struct Node* node;
    int hd;
};

void findMinMax(struct Node* root, int *min, int *max, int hd) {
    if (root == NULL) return;
    if (hd < *min) *min = hd;
    if (hd > *max) *max = hd;
    findMinMax(root->left, min, max, hd - 1);
    findMinMax(root->right, min, max, hd + 1);
}

void printVerticalLine(struct Node* root, int line, int hd) {
    if (root == NULL) return;
    if (hd == line) printf("%d ", root->data);
    printVerticalLine(root->left, line, hd - 1);
    printVerticalLine(root->right, line, hd + 1);
}

void verticalOrder(struct Node* root) {
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);

    for (int line = min; line <= max; line++) {
        printVerticalLine(root, line, 0);
        printf("\n");
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Vertical Order Traversal:\n");
    verticalOrder(root);

    return 0;
}
