#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m, val;
    struct Node *list1 = NULL, *list2 = NULL, *temp = NULL;

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &val);
        if(!list1) { list1 = temp = createNode(val); }
        else { temp->next = createNode(val); temp = temp->next; }
    }

    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d", &val);
        if(!list2) { list2 = temp = createNode(val); }
        else { temp->next = createNode(val); temp = temp->next; }
    }

    struct Node *dummy = createNode(0); 
    struct Node *curr = dummy;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            curr->next = list1;
            list1 = list1->next;
        } else {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }

    if (list1 != NULL) curr->next = list1;
    else curr->next = list2;

    struct Node *result = dummy->next;
    while (result != NULL) {
        printf("%d ", result->data);
        result = result->next;
    }

    return 0;
}