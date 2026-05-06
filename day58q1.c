#include <stdio.h>
#include <stdlib.h>

// Define structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Utility function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Search for index of value in inorder[]
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) return i;
    }
    return -1;
}

// Recursive function to build tree
struct Node* buildTree(int preorder[], int inorder[], int start, int end, int* preorderIndex) {
    if (start > end) return NULL;

    // Pick current node from preorder
    int current = preorder[*preorderIndex];
    (*preorderIndex)++;
    struct Node* node = newNode(current);

    // If leaf node
    if (start == end) return node;

    // Find position in inorder
    int pos = search(inorder, start, end, current);

    // Build left and right subtrees
    node->left = buildTree(preorder, inorder, start, pos - 1, preorderIndex);
    node->right = buildTree(preorder, inorder, pos + 1, end, preorderIndex);

    return node;
}

// Print postorder traversal
void printPostorder(struct Node* root) {
    if (root == NULL) return;
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int N;
    scanf("%d", &N);

    int preorder[N], inorder[N];
    for (int i = 0; i < N; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < N; i++) scanf("%d", &inorder[i]);

    int preorderIndex = 0;
    struct Node* root = buildTree(preorder, inorder, 0, N - 1, &preorderIndex);

    printPostorder(root);
    return 0;
}