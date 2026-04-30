#include <stdio.h>

#define MAX 100

int main()
{
    int queue[MAX];
    int front = 0, rear = -1;
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        rear++;
        scanf("%d", &queue[rear]);
    }
    
    printf("Queue elements are:\n");
    for(i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}