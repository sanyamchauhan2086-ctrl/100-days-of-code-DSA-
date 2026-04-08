/*
Day 68 - Question 1: Topological Sort (Kahn’s BFS Algorithm)

Problem:
Implement topological sorting using in-degree array and queue.

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

    int indegree[n];
    for (int i = 0; i < n; i++)
        indegree[i] = 0;

    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        addEdge(adj, u, v);

        // increase indegree of v
        indegree[v]++;
    }

    printf("\nInitial In-Degree:\n");
    for (int i = 0; i < n; i++)
        printf("Node %d → %d\n", i, indegree[i]);

    // queue
    int queue[n];
    int front = 0, rear = 0;

    // push nodes with indegree 0
    printf("\nAdding nodes with indegree 0 to queue:\n");
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            printf("Pushed %d into queue\n", i);
            queue[rear++] = i;
        }
    }

    int topo[n];
    int index = 0;

    printf("\n--- Starting BFS (Kahn's Algorithm) ---\n");

    while (front < rear)
    {
        int curr = queue[front++];
        topo[index++] = curr;

        printf("\nProcessing node %d\n", curr);

        node* temp = adj[curr];

        while (temp != NULL)
        {
            int neighbor = temp->data;

            indegree[neighbor]--;
            printf("Decreased indegree of %d → %d\n", neighbor, indegree[neighbor]);

            if (indegree[neighbor] == 0)
            {
                printf("Pushed %d into queue\n", neighbor);
                queue[rear++] = neighbor;
            }

            temp = temp->next;
        }
    }

    printf("\n--- Topological Order ---\n");

    if (index != n)
    {
        printf("Cycle detected! Topological sort not possible\n");
    }
    else
    {
        for (int i = 0; i < index; i++)
            printf("%d ", topo[i]);
        printf("\n");
    }

    return 0;
}