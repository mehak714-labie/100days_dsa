#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

int getHeight(struct Node* root) {
    if (root == NULL) return 0;
    
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    if (N <= 0) {
        printf("0\n");
        return 0;
    }

    int *arr = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node** queue = (struct Node**)malloc(N * sizeof(struct Node*));
    int head = 0, tail = 0;

    struct Node* root = newNode(arr[0]);
    if (root) queue[tail++] = root;

    int i = 1;
    while (head < tail && i < N) {
        struct Node* current = queue[head++];

        if (i < N) {
            current->left = newNode(arr[i++]);
            if (current->left) queue[tail++] = current->left;
        }

        if (i < N) {
            current->right = newNode(arr[i++]);
            if (current->right) queue[tail++] = current->right;
        }
    }

    printf("%d\n", getHeight(root));

    free(arr);
    free(queue);
    return 0;
}