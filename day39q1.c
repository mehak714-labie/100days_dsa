#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int val) {
    if (size >= MAX) return;
    heap[size] = val;
    int current = size;
    size++;

    // Heapify up
    while (current != 0 && heap[(current - 1) / 2] > heap[current]) {
        swap(&heap[current], &heap[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
}

void minHeapify(int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != idx) {
        swap(&heap[idx], &heap[smallest]);
        minHeapify(smallest);
    }
}

int extractMin() {
    if (size <= 0) return -1;
    if (size == 1) return heap[--size];

    int root = heap[0];
    heap[0] = heap[--size];
    minHeapify(0);
    return root;
}

int peek() {
    if (size <= 0) return -1;
    return heap[0];
}

int main() {
    int n, val;
    char op[20];
    if (scanf("%d", &n) != 1) return 0;

    while (n--) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }
    return 0;
}