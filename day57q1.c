#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to mirror the binary tree
void mirror(struct Node* root) {
    if (root == NULL) return;

    // Mirror left and right subtrees
    mirror(root->left);
    mirror(root->right);

    // Swap left and right pointers
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    // Example tree construction
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Inorder traversal before mirroring:\n");
    inorder(root);

    mirror(root);

    printf("\nInorder traversal after mirroring:\n");
    inorder(root);

    return 0;
}
