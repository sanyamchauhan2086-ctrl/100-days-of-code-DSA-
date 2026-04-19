/*
Day 79 - Question 1: Single Source Shortest Path using Dijkstra’s Algorithm

Problem Statement:
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format:
n m
u v w
source

Output Format:
Distances to all vertices.

Sample Input:
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output:
0 2 3 9 6

Explanation:
Shortest distances computed via priority queue.
*/

#include <stdio.h>
#include <limits.h>

#define MAX 100

// Function to find node with minimum distance
int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, minIndex = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

int main() {

    int n, m;
    printf("Enter number of nodes (n) and edges (m): ");
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    // Initialize graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v w):\n");

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w; // undirected
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    int dist[MAX], visited[MAX];

    // Initialize
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (int count = 1; count <= n; count++) {

        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Shortest distances from source %d:\n", source);

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    printf("\n");

    return 0;
}