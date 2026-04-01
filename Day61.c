#include <stdio.h>

/*
Day 61 - Question 1: Graph Representation Using Adjacency Matrix

Problem:
Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- n x n adjacency matrix
*/

// ----------- MAIN -----------
int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    int adj[100][100] = {0};

    int u, v;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // Assuming 0-based indexing
        adj[u][v] = 1;

        // For undirected graph, also mark reverse
        adj[v][u] = 1;
    }

    // ----------- PRINT MATRIX -----------
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}