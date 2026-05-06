#include <stdio.h>
#include <stdlib.h>

// Define structure for tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Search for index of value in inorder[]
int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val) return i;
    }
    return -1;
}

// Recursive function to build tree
struct TreeNode* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int *postIndex) {
    if (inStart > inEnd) return NULL;

    // Current root from postorder
    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = newNode(rootVal);

    // If no children
    if (inStart == inEnd) return root;

    // Find root in inorder
    int inIndex = search(inorder, inStart, inEnd, rootVal);

    // Build right subtree first (postorder is left-right-root)
    root->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left  = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

// Print preorder traversal
void preorder(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int N;
    scanf("%d", &N);

    int inorder[N], postorder[N];
    for (int i = 0; i < N; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < N; i++) scanf("%d", &postorder[i]);

    int postIndex = N - 1;
    struct TreeNode* root = buildTree(inorder, postorder, 0, N - 1, &postIndex);

    preorder(root);
    return 0;
}
