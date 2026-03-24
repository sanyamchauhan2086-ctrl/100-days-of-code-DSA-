/*
Day XX - Vertical Order Traversal of Binary Tree

Problem:
Given a binary tree, print its vertical order traversal.
Nodes on the same vertical line (same horizontal distance)
are printed together from top to bottom.

Input Format:
- First line: integer N
- Second line: N space-separated integers (level order)
- Use -1 for NULL

Example Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7
*/

#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue node with horizontal distance
struct QNode {
    struct TreeNode* node;
    int hd;
};

// Queue
struct Queue {
    struct QNode* arr;
    int front, rear, size;
};

// Create queue
struct Queue* createQueue(int n) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct QNode*)malloc(sizeof(struct QNode) * n);
    q->front = q->rear = q->size = 0;
    return q;
}

int isEmpty(struct Queue* q) {
    return q->size == 0;
}

void enqueue(struct Queue* q, struct TreeNode* node, int hd) {
    q->arr[q->rear].node = node;
    q->arr[q->rear].hd = hd;
    q->rear++;
    q->size++;
}

struct QNode dequeue(struct Queue* q) {
    q->size--;
    return q->arr[q->front++];
}

// Build tree
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode* root = createNode(arr[0]);

    struct Queue* q = createQueue(n);
    enqueue(q, root, 0);

    int i = 1;

    while (!isEmpty(q) && i < n) {
        struct QNode temp = dequeue(q);
        struct TreeNode* curr = temp.node;

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(q, curr->left, 0);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(q, curr->right, 0);
        }
        i++;
    }

    return root;
}

// Vertical Order Traversal
void verticalOrder(struct TreeNode* root, int n) {
    if (root == NULL)
        return;

    // Range of horizontal distance
    int min = -n, max = n;

    // Array of lists
    int columns[2*n][n];
    int counts[2*n];

    for (int i = 0; i < 2*n; i++)
        counts[i] = 0;

    struct Queue* q = createQueue(n);
    enqueue(q, root, 0);

    while (!isEmpty(q)) {
        struct QNode temp = dequeue(q);
        struct TreeNode* node = temp.node;
        int hd = temp.hd;

        int index = hd + n; // shift to positive index

        columns[index][counts[index]++] = node->val;

        if (node->left)
            enqueue(q, node->left, hd - 1);

        if (node->right)
            enqueue(q, node->right, hd + 1);
    }

    printf("\nVertical Order Traversal:\n");

    for (int i = 0; i < 2*n; i++) {
        if (counts[i] > 0) {
            for (int j = 0; j < counts[i]; j++) {
                printf("%d ", columns[i][j]);
            }
            printf("\n");
        }
    }
}

// Main
int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter level order values (-1 for NULL):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    verticalOrder(root, n);

    return 0;
}