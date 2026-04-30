#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    if (front == NULL) return -1;

    struct Node* temp = front;
    int val = temp->data;
    front = front->next;

    if (front == NULL) rear = NULL;

    free(temp);
    return val;
}

int main() {
    int n, val;
    char op[20];
    
    if (scanf("%d", &n) != 1) return 0;

    while (n--) {
        scanf("%s", op);
        if (strcmp(op, "enqueue") == 0) {
            scanf("%d", &val);
            enqueue(val);
        } else if (strcmp(op, "dequeue") == 0) {
            printf("%d\n", dequeue());
        }
    }
    return 0;
}