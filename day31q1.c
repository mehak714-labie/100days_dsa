#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

// push function
void push(char x) {
    stack[++top] = x;
}

// pop function
char pop() {
    return stack[top--];
}

// precedence function
int priority(char x) {
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

int main() {
    char infix[100], postfix[100];
    int i = 0, j = 0;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0') {
        
        if (isalnum(infix[i])) {          // operand
            postfix[j++] = infix[i];
        }
        else {                            // operator
            while (top != -1 && priority(stack[top]) >= priority(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }

        i++;
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s", postfix);

    return 0;
}