/*
Day 69 - Question 1: Dijkstra’s Algorithm (Shortest Path)

Problem:
Given a weighted graph with non-negative edge weights, compute the shortest
distance from a given source vertex to all other vertices using Dijkstra’s Algorithm.
Implement the algorithm using a Priority Queue approach.

Input:
- Number of vertices
- Adjacency matrix (weights, 0 if no edge)
- Source vertex

Output:
- Shortest distance from source to every vertex
*/

#include <stdio.h>
#include <limits.h>

#define MAX 100

// Function to find vertex with minimum distance (like priority queue)
int getMinVertex(int dist[], int visited[], int n) {
    int min = INT_MAX, minIndex = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Dijkstra function
void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[MAX];
    int visited[MAX];

    // Initialize distances and visited array
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    printf("\nStarting Dijkstra’s Algorithm from source node %d...\n", src);

    for (int count = 0; count < n - 1; count++) {

        int u = getMinVertex(dist, visited, n);

        if (u == -1) break;

        visited[u] = 1;

        printf("\nSelected next minimum node: %d (Distance = %d)\n", u, dist[u]);

        // Update distances of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != 0 && dist[u] != INT_MAX) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    printf("Updating distance of node %d: %d -> %d\n",
                           v, dist[v], dist[u] + graph[u][v]);

                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // Print final shortest distances
    printf("\n===== Shortest Distances from Source Node %d =====\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("Node %d: Not reachable\n", i);
        else
            printf("Node %d: %d\n", i, dist[i]);
    }
}

// Main function
int main() {
    int n, graph[MAX][MAX], src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nEnter source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, n, src);

    return 0;
}