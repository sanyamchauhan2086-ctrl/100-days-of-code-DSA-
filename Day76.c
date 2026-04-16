/*
Day 76 - Question 1: Count Connected Components (Undirected Graph)

Problem Statement:
Using DFS or BFS, count number of connected components.

Input Format:
n m
edges

Output Format:
Number of connected components.

Sample Input:
6 3
1 2
2 3
5 6

Sample Output:
3

Explanation:
Components: {1,2,3}, {4}, {5,6}
*/

#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS
void dfs(int node, struct Node* adj[], int visited[]) {
    visited[node] = 1;

    struct Node* temp = adj[node];

    while (temp != NULL) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }

        temp = temp->next;
    }
}

int main() {

    int n, m;

    printf("Enter number of nodes (n) and edges (m): ");
    scanf("%d %d", &n, &m);

    // adjacency list (1-based indexing)
    struct Node* adj[n + 1];

    // initialize
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
    }

    printf("Enter the edges (u v):\n");

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        addEdge(adj, u, v);
    }

    int visited[n + 1];

    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }

    int components = 0;

    // check all nodes
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components++;
            dfs(i, adj, visited);
        }
    }

    printf("Number of connected components: %d\n", components);

    return 0;
}