#include <stdio.h>

int main() {
    int n, m, val;
    int stack[1000]; // Array-based stack
    int top = -1;

    // Input number of elements to push
    if (scanf("%d", &n) != 1) return 0;

    // Push elements onto the stack
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        stack[++top] = val;
    }

    // Input number of elements to pop
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        if (top >= 0) {
            top--; // Move pointer down to "pop"
        }
    }

    // Print remaining elements from top to bottom
    for (int i = top; i >= 0; i--) {
        printf("%d%s", stack[i], (i == 0 ? "" : " "));
    }
    printf("\n");

    return 0;
}