#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// add edge to adjacency list
void addEdge(Node* adjList[], int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

// DFS utility
bool dfsUtil(Node* adjList[], int v, bool visited[], bool recStack[]) {
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;

        Node* temp = adjList[v];
        while (temp != NULL) {
            int u = temp->vertex;
            if (!visited[u] && dfsUtil(adjList, u, visited, recStack))
                return true;
            else if (recStack[u])
                return true;
            temp = temp->next;
        }
    }
    recStack[v] = false;
    return false;
}

// cycle detection
bool isCyclic(Node* adjList[], int V) {
    bool visited[V];
    bool recStack[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if (dfsUtil(adjList, i, visited, recStack))
            return true;
    }
    return false;
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    Node* adjList[V];
    for (int i = 0; i < V; i++)
        adjList[i] = NULL;

    printf("Enter edges (src dest):\n");
    for (int i = 0; i < E; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(adjList, src, dest);
    }

    if (isCyclic(adjList, V))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
