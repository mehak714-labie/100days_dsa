#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void rightViewUtil(struct TreeNode* root, int level, int* maxLevel) {
    if (root == NULL) return;

    if (*maxLevel < level) {
        printf("%d ", root->val);
        *maxLevel = level;
    }

    rightViewUtil(root->right, level + 1, maxLevel);
    rightViewUtil(root->left, level + 1, maxLevel);
}

void rightView(struct TreeNode* root) {
    int maxLevel = 0;
    rightViewUtil(root, 1, &maxLevel);
}

int main() {

    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printf("Right Side View: ");
    rightView(root);

    return 0;
}
