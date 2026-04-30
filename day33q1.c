#include <stdio.h>

// Function to determine operator precedence
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    char infix[100], stack[100];
    int top = -1;

    // Read the infix expression
    if (scanf("%s", infix) != 1) return 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // If character is an operand (letter or number), print it immediately
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            printf("%c", c);
        } 
        else if (c == '(') {
            stack[++top] = c;
        } 
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                printf("%c", stack[top--]);
            }
            top--; // Pop the '('
        } 
        else {
            // Operator encountered
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                printf("%c", stack[top--]);
            }
            stack[++top] = c;
        }
    }

    // Pop all remaining operators from the stack
    while (top != -1) {
        printf("%c", stack[top--]);
    }
    printf("\n");

    return 0;
}