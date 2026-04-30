#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, key, i, count = 0;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        
        printf("Enter value %d: ", i+1);
        scanf("%d", &newNode->data);
        
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;   
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Enter key to count: ");
    scanf("%d", &key);

    temp = head;
    while(temp != NULL) {
        if(temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    printf("Count of %d = %d\n", key, count);

    return 0;
}