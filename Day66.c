/*
Day 66 - Question 1: Cycle Detection in Directed Graph

Problem:
Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists
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

// DFS for cycle detection
int dfs(int curr, node* adj[], int visited[], int recStack[])
{
    printf("\nVisiting Node: %d\n", curr);

    visited[curr] = 1;
    recStack[curr] = 1;

    node* temp = adj[curr];

    while (temp != NULL)
    {
        int neighbor = temp->data;

        printf("Checking edge %d -> %d\n", curr, neighbor);

        // Case 1: Not visited
        if (!visited[neighbor])
        {
            printf("Node %d not visited → going deeper\n", neighbor);

            if (dfs(neighbor, adj, visited, recStack))
                return 1;
        }
        // Case 2: Already in recursion stack → cycle
        else if (recStack[neighbor])
        {
            printf("Cycle detected! Node %d is already in recursion stack\n", neighbor);
            return 1;
        }
        else
        {
            printf("Node %d already visited and not in stack → ignore\n", neighbor);
        }

        temp = temp->next;
    }

    // remove from recursion stack (backtracking)
    recStack[curr] = 0;
    printf("Backtracking from node %d (removed from recursion stack)\n", curr);

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

    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int visited[n];
    int recStack[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        recStack[i] = 0;
    }

    int hasCycle = 0;

    printf("\n--- Starting DFS Traversal ---\n");

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printf("\nStarting DFS from node %d\n", i);

            if (dfs(i, adj, visited, recStack))
            {
                hasCycle = 1;
                break;
            }
        }
    }

    printf("\n--- Result ---\n");

    if (hasCycle)
        printf("Cycle exists → YES\n");
    else
        printf("No cycle → NO\n");

    return 0;
}