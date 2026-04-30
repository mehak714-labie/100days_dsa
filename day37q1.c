#include <stdio.h>

#define MAX 1000

int arr[MAX];
int size = 0;

void insert(int x) {
    if (size < MAX) {
        arr[size++] = x;
    }
}

void delete_element() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    // Find index of minimum element
    int min_idx = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[min_idx]) {
            min_idx = i;
        }
    }

    printf("%d\n", arr[min_idx]);

    // Remove element by shifting remaining elements to the left
    for (int i = min_idx; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void peek() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    int min_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    printf("%d\n", min_val);
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    while (N--) {
        char op[10];
        scanf("%s", op);
        if (op[0] == 'i') { // insert
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (op[0] == 'd') { // delete
            delete_element();
        } else if (op[0] == 'p') { // peek
            peek();
        }
    }
    return 0;
}