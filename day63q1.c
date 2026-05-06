#include <stdio.h>

#define MAX 100

int visited[MAX];
int n; // number of vertices

void dfs(int adj[MAX][MAX], int s) {
    visited[s] = 1;
    printf("%d ", s);

    for (int i = 0; i < n; i++) {
        if (adj[s][i] == 1 && !visited[i]) {
            dfs(adj, i);
        }
    }
}

int main() {
    int adj[MAX][MAX];
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter each edge (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(adj, start);

    return 0;
}
