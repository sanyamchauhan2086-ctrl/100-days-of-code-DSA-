/*
Day 64 - Question 1: Breadth First Search (BFS)

Problem:
Perform BFS from a given source using queue.

Input:
- n (number of vertices)
- adjacency list (edges)
- source s

Output:
- BFS traversal order
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

// BFS function
void bfs(int start, node* adj[], int visited[], int n)
{
    int queue[n];
    int front = 0, rear = 0;

    // push start
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        int curr = queue[front++];
        printf("%d ", curr);

        node* temp = adj[curr];

        while (temp != NULL)
        {
            if (!visited[temp->data])
            {
                visited[temp->data] = 1;
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
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

    printf("\nBFS Traversal:\n");
    bfs(start, adj, visited, n);

    return 0;
}