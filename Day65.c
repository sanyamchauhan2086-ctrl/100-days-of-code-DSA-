/*
Day 65 - Question 1: Cycle Detection in Undirected Graph (DFS)

Problem:
Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO
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

// DFS for cycle detection
int dfs(int curr, int parent, node* adj[], int visited[])
{
    printf("\nVisiting Node: %d (Parent: %d)\n", curr, parent);

    visited[curr] = 1;

    node* temp = adj[curr];

    while (temp != NULL)
    {
        int neighbor = temp->data;

        printf("Checking neighbor %d of node %d\n", neighbor, curr);

        if (!visited[neighbor])
        {
            printf("Neighbor %d not visited → going deeper\n", neighbor);

            if (dfs(neighbor, curr, adj, visited))
                return 1;
        }
        else if (neighbor != parent)
        {
            printf("Cycle detected at node %d via neighbor %d\n", curr, neighbor);
            return 1;
        }
        else
        {
            printf("Neighbor %d is parent → ignore\n", neighbor);
        }

        temp = temp->next;
    }

    return 0;
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

    int hasCycle = 0;

    printf("\n--- Starting DFS Traversal ---\n");

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printf("\nStarting new DFS from node %d\n", i);

            if (dfs(i, -1, adj, visited))
            {
                hasCycle = 1;
                break;
            }
        }
    }

    printf("\n--- Result ---\n");

    if (hasCycle)
        printf("Graph contains a cycle → YES\n");
    else
        printf("Graph does NOT contain a cycle → NO\n");

    return 0;
}