#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to perform Kahn's Algorithm
void topologicalSort(int n, int adj[MAX][MAX]) {
    int indegree[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    int count = 0;

    // Step 1: Calculate indegree of each node
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j]) {
                indegree[j]++;
            }
        }
    }

    // Step 2: Enqueue all vertices with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Step 3: Process the queue
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);  // Print the node in topological order
        count++;

        // Reduce indegree of neighbors
        for (int j = 0; j < n; j++) {
            if (adj[node][j]) {
                indegree[j]--;
                if (indegree[j] == 0) {
                    queue[rear++] = j;
                }
            }
        }
    }

    // Step 4: Check for cycle
    if (count != n) {
        printf("\nGraph has a cycle, topological sort not possible.\n");
    }
}

int main() {
    int n, e;
    int adj[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;  // Directed edge u -> v
    }

    printf("Topological Sort (Kahn's Algorithm):\n");
    topologicalSort(n, adj);

    return 0;
}
