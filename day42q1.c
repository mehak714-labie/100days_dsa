#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Simple Array-based Queue
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int val) { queue[rear++] = val; }
int dequeue() { return queue[front++]; }
int isEmpty() { return front == rear; }

// Simple Array-based Stack
int stack[MAX];
int top = -1;

void push(int val) { stack[++top] = val; }
int pop() { return stack[top--]; }
int isStackEmpty() { return top == -1; }

int main() {
    int n, val;
    if (scanf("%d", &n) != 1) return 0;

    // Read queue
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }

    // 1. Move all elements from Queue to Stack
    while (!isEmpty()) {
        push(dequeue());
    }

    // 2. Pop from Stack and move back to Queue
    while (!isStackEmpty()) {
        enqueue(pop());
    }

    // 3. Print the reversed queue
    for (int i = 0; i < n; i++) {
        printf("%d ", dequeue());
    }
    printf("\n");

    return 0;
}