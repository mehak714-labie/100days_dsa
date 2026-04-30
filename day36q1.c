#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1, n;

// Enqueue function
void enqueue(int value) {
    if ((rear + 1) % n == front) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % n;
    queue[rear] = value;
}

// Dequeue function
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % n;
    }
}

// Display queue
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % n;
    }
}

int main() {
    int elements, operations, i, value;

    printf("Enter number of elements: ");
    scanf("%d", &elements);

    n = elements + 5;   // queue capacity

    printf("Enter elements:\n");
    for (i = 0; i < elements; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    printf("Enter number of dequeue operations: ");
    scanf("%d", &operations);

    for (i = 0; i < operations; i++) {
        dequeue();
    }

    printf("Queue after operations:\n");
    display();

    return 0;
}