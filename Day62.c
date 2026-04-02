/*
Day 62 - Question 1: Graph Representation Using Adjacency List

Problem:
Build a graph with adjacency list representation using linked lists.

Input:
- n (number of vertices)
- m (number of edges)
- edges (u, v)

Output:
- Print adjacency list for each vertex
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for adjacency list
typedef struct node
{
    int data;
    struct node* next;
} node;

// Create new node
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
    // u -> v
    node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    // v -> u
    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Print adjacency list
void printGraph(node* adj[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d -> ", i);

        node* temp = adj[i];
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
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

    printf("\nAdjacency List:\n");
    printGraph(adj, n);

    return 0;
}