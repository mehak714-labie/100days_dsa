#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue implementation
int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if(rear == MAX-1) return; // overflow
    if(front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if(front == -1 || front > rear) return -1; // empty
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void BFS(int n, int adj[n][n], int source) {
    int visited[n];
    for(int i=0; i<n; i++) visited[i] = 0;

    enqueue(source);
    visited[source] = 1;

    printf("BFS Traversal: ");
    while(!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for(int i=0; i<n; i++) {
            if(adj[node][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, source;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int adj[n][n];
    printf("Enter adjacency matrix:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter source node: ");
    scanf("%d", &source);

    BFS(n, adj, source);

    return 0;
}