#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

bool isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

bool isEmpty() {
    return (front == -1);
}

void push_back(int value) {
    if (isFull()) {
        printf("Deque is full!\n");
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    deque[rear] = value;
    printf("Inserted %d at rear.\n", value);
}

void pop_front() {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deleted %d from front.\n", deque[front]);
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
}

int main() {
    push_back(10);
    push_back(20);
    pop_front();
    return 0;
}