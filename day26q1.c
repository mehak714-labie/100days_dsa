#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Doubly Linked List node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node in dynamic memory
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int main() {
    int n, value;
    struct Node *head = NULL, *tail = NULL;

    // Read the number of elements
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head == NULL) {
            // First node becomes the head
            head = newNode;
            tail = newNode;
        } else {
            // Link the new node to the end of the list
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode; // Move tail to the new node
        }
    }

    // Traversal: Print elements from head using the next pointer
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" ");
        }
        temp = temp->next;
    }
    printf("\n");

    // Clean up memory (Freeing allocated nodes)
    temp = head;
    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}