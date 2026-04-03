/*
Day 63 - Question 1: Depth First Search (DFS)

Problem:
Perform DFS starting from a given source vertex using recursion.

Input:
- n (number of vertices)
- adjacency list (edges)
- starting vertex s

Output:
- DFS traversal order
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node
{
    int data;
    struct node* next;
} node;

// Create node
node* createNode(int value)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(node* adj[], int u, int v)
{
    node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS function
void dfs(int nodeVal, node* adj[], int visited[])
{
    visited[nodeVal] = 1;
    printf("%d ", nodeVal);

    node* temp = adj[nodeVal];

    while (temp != NULL)
    {
        if (!visited[temp->data])
        {
            dfs(temp->data, adj, visited);
        }
        temp = temp->next;
    }
}

int main()
{
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    node* adj[n];

    // initialize
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("\nDFS Traversal:\n");
    dfs(start, adj, visited);

    return 0;
}