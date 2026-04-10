/*
Day 70 - Question 2: Bellman-Ford Algorithm (Shortest Path + Negative Cycle Detection)

Problem:
Given a graph with 'n' vertices and 'm' edges (u, v, w), compute the shortest
distance from a source vertex to all other vertices using Bellman-Ford Algorithm.
Also detect if the graph contains a negative weight cycle.

Input:
- Number of vertices (n)
- Number of edges (m)
- m edges in the format (u, v, w)
- Source vertex

Output:
- Shortest distances from source to all vertices
  OR
- Print "NEGATIVE WEIGHT CYCLE DETECTED"
*/

#include <stdio.h>
#include <limits.h>

#define MAX 100

// Structure to store an edge
struct Edge {
    int u, v, w;
};

void bellmanFord(struct Edge edges[], int n, int m, int src) {
    int dist[MAX];

    // Step 1: Initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    printf("\nStarting Bellman-Ford from source node %d...\n", src);

    // Step 2: Relax all edges (n-1) times
    for (int i = 1; i <= n - 1; i++) {
        printf("\n--- Iteration %d ---\n", i);

        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                printf("Updating dist[%d]: %d -> %d (via %d)\n",
                       v, dist[v], dist[u] + w, u);

                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 3: Check for negative weight cycles
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("\nNEGATIVE WEIGHT CYCLE DETECTED\n");
            return;
        }
    }

    // Step 4: Print shortest distances
    printf("\n===== Shortest Distances from Source %d =====\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("Node %d: Not reachable\n", i);
        else
            printf("Node %d: %d\n", i, dist[i]);
    }
}

// Main function
int main() {
    int n, m, src;

    struct Edge edges[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("\nEnter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    printf("\nEnter source vertex: ");
    scanf("%d", &src);

    bellmanFord(edges, n, m, src);

    return 0;
}