/*
Day 67 - Question 1: Topological Sort (DFS)

Problem:
Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

Output:
- Topological order
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

// Add edge (DIRECTED)
void addEdge(node* adj[], int u, int v)
{
    node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS function for topo sort
void dfs(int curr, node* adj[], int visited[], int stack[], int* top)
{
    printf("\nVisiting Node: %d\n", curr);

    visited[curr] = 1;

    node* temp = adj[curr];

    while (temp != NULL)
    {
        int neighbor = temp->data;

        printf("Checking edge %d -> %d\n", curr, neighbor);

        if (!visited[neighbor])
        {
            printf("Going deeper to %d\n", neighbor);
            dfs(neighbor, adj, visited, stack, top);
        }

        temp = temp->next;
    }

    // push into stack after visiting all neighbors
    stack[++(*top)] = curr;
    printf("Pushed %d to stack\n", curr);
}

int main()
{
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    node* adj[n];

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int stack[n];
    int top = -1;

    printf("\n--- Starting DFS for Topological Sort ---\n");

    // handle multiple components
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printf("\nStarting DFS from node %d\n", i);
            dfs(i, adj, visited, stack, &top);
        }
    }

    printf("\n--- Topological Order ---\n");

    // print in reverse stack order
    while (top >= 0)
    {
        printf("%d ", stack[top--]);
    }

    printf("\n");

    return 0;
}