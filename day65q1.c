#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(Node* adj[], int u, int v) {
    Node* nodeV = createNode(v);
    nodeV->next = adj[u];
    adj[u] = nodeV;

    Node* nodeU = createNode(u);
    nodeU->next = adj[v];
    adj[v] = nodeU;
}

// DFS function
bool dfs(int node, int parent, bool visited[], Node* adj[]) {
    visited[node] = true;

    Node* temp = adj[node];
    while (temp != NULL) {
        int nei = temp->vertex;
        if (!visited[nei]) {
            if (dfs(nei, node, visited, adj)) return true;
        } else if (nei != parent) {
            return true; // Found cycle
        }
        temp = temp->next;
    }
    return false;
}

// Main cycle detection
bool hasCycle(int V, Node* adj[]) {
    bool visited[V];
    for (int i = 0; i < V; i++) visited[i] = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj)) return true;
        }
    }
    return false;
}

int main() {
    int V = 4, E = 4;
    int edges[4][2] = {{0,1}, {0,2}, {1,2}, {2,3}};

    Node* adj[V];
    for (int i = 0; i < V; i++) adj[i] = NULL;

    for (int i = 0; i < E; i++) {
        addEdge(adj, edges[i][0], edges[i][1]);
    }

    if (hasCycle(V, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
