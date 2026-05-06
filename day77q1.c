#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int adj[MAX][MAX];   // adjacency matrix
int visited[MAX];
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int v) {
    queue[rear++] = v;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void bfs(int start, int n) {
    visited[start] = 1;
    enqueue(start);

    while (!isEmpty()) {
        int u = dequeue();
        for (int v = 1; v <= n; v++) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = 1;
                enqueue(v);
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    // read edges
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a][b] = 1;
        adj[b][a] = 1; // undirected
    }

    // run BFS from node 1
    bfs(1, n);

    // check connectivity
    int connected = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");

    return 0;
}