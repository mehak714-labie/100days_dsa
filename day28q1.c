#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, value, i;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("List is empty");
        return 0;
    }

    for (i = 0; i < n; i++) {

        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter value: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        }
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    temp->next = head;

    printf("Circular Linked List: ");

    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    return 0;
}