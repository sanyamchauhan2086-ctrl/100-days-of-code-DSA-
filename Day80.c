/*
Day 80 - Question 1: Floyd-Warshall Algorithm

Problem:
Given a weighted graph with n vertices, compute shortest distances
between every pair of vertices.

Input:
- n (number of vertices)
- n x n adjacency matrix
  (-1 means no direct edge)

Output:
- Shortest distance matrix

Example:
Input:
4
0 5 -1 10
-1 0 3 -1
-1 -1 0 1
-1 -1 -1 0

Output:
0 5 8 9
-1 0 3 4
-1 -1 0 1
-1 -1 -1 0
*/

#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 1000000000  // large value

int main() {

    int n;
    printf("Enter number of vertices (n): ");
    scanf("%d", &n);

    int dist[MAX][MAX];

    printf("Enter adjacency matrix (-1 for no edge):\n");

    // Input + convert -1 to INF
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);

            if (dist[i][j] == -1 && i != j) {
                dist[i][j] = INF;
            }
        }
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("\nShortest distance matrix:\n");

    // Output (convert INF back to -1)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (dist[i][j] == INF)
                printf("-1 ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}