#include <stdio.h>
#include <limits.h>

#define MAXN 100
#define MAXE 10000

// Structure for edges
typedef struct {
    int u, v, w;
} Edge;

int main() {
    int n, e, k;
    Edge edges[MAXE];
    
    // Example input: times = [[2,1,1],[2,3,1],[3,4,1]], n=4, k=2
    // First line: number of nodes, number of edges, source
    // Next e lines: u v w
    printf("Enter n, e, k: ");
    scanf("%d %d %d", &n, &e, &k);
    
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    
    // Distance array
    int dist[MAXN];
    int visited[MAXN];
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[k] = 0;
    
    // Dijkstra using simple array (O(n^2))
    for (int i = 1; i <= n; i++) {
        int u = -1;
        int minDist = INT_MAX;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }
        if (u == -1) break;
        visited[u] = 1;
        
        // Relax edges
        for (int j = 0; j < e; j++) {
            if (edges[j].u == u) {
                int v = edges[j].v;
                int w = edges[j].w;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
    
    // Find max distance
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            printf("-1\n");
            return 0;
        }
        if (dist[i] > ans) ans = dist[i];
    }
    
    printf("Minimum time: %d\n", ans);
    return 0;
}
