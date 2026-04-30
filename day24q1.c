#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* deleteFirst(struct Node* head, int key) {
    
    struct Node *temp = head, *prev = NULL;

    if (temp != NULL && temp->data == key) {
        head = temp->next;   
        free(temp);         
        return head;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key not found!\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);

    return head;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    int n, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = NULL, *newNode, *temp = NULL;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }

    printf("Enter key to delete: ");
    scanf("%d", &key);

    head = deleteFirst(head, key);

    printf("Linked List after deletion:\n");
    printList(head);

    return 0;
}