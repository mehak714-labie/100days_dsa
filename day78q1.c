#include <stdio.h>
#include <stdbool.h>
#define INF 999999

int minKey(int key[], bool mstSet[], int V) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int primMST(int V, int graph[V][V]) {
    int parent[V];   // store MST
    int key[V];      // min edge weight
    bool mstSet[V];  // included in MST

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;      // start from vertex 0
    parent[0] = -1;  // root has no parent

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalWeight = 0;
    for (int i = 1; i < V; i++) {
        totalWeight += graph[i][parent[i]];
    }
    return totalWeight;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int graph[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        // zero-based indexing assumed
        graph[u-1][v-1] = w;
        graph[v-1][u-1] = w;
    }

    int result = primMST(V, graph);
    printf("%d\n", result);

    return 0;
}