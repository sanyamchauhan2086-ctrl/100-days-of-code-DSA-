/*
Day 77 - Question 1: Check if Graph is Connected

Problem Statement:
Using BFS or DFS, check if the entire graph is connected.

Input Format:
n m
edges

Output Format:
CONNECTED
NOT CONNECTED

Sample Input:
4 2
1 2
3 4

Sample Output:
NOT CONNECTED
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

    struct Node* temp = adj[node;

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

    struct Node* adj[n + 1];

    // Initialize adjacency list
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

    // Start DFS from node 1
    dfs(1, adj, visited);

    // Check if all nodes are visited
    int isConnected = 1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            isConnected = 0;
            break;
        }
    }

    if (isConnected)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");

    return 0;
}