/*
Day 46 - Question 1: Level Order Traversal

Problem:
Given a binary tree, print its level order traversal.
(Level by level from left to right)

Input:
- First enter number of nodes (n)
- Then enter node values in level order
- Use -1 for NULL nodes

Example Input:
7
3 9 20 -1 -1 15 7

Output:
Level Order Traversal:
3
9 20
15 7
*/

#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue for BFS
struct Queue {
    struct TreeNode** arr;
    int front, rear, size, capacity;
};

// Create queue
struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    q->arr = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * capacity);
    return q;
}

// Check empty
int isEmpty(struct Queue* q) {
    return q->size == 0;
}

// Enqueue
void enqueue(struct Queue* q, struct TreeNode* node) {
    if (q->rear == q->capacity) return; // safety
    q->arr[q->rear++] = node;
    q->size++;
}

// Dequeue
struct TreeNode* dequeue(struct Queue* q) {
    q->size--;
    return q->arr[q->front++];
}

// Build tree from level order input
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode* root = createNode(arr[0]);

    struct Queue* q = createQueue(n);
    enqueue(q, root);

    int i = 1;

    while (!isEmpty(q) && i < n) {
        struct TreeNode* curr = dequeue(q);

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(q, curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(q, curr->right);
        }
        i++;
    }

    return root;
}

// Level Order Traversal
void levelOrder(struct TreeNode* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    struct Queue* q = createQueue(1000);
    enqueue(q, root);

    printf("\nLevel Order Traversal:\n");

    while (!isEmpty(q)) {
        int levelSize = q->size;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(q);

            printf("%d ", node->val);

            if (node->left)
                enqueue(q, node->left);
            if (node->right)
                enqueue(q, node->right);
        }

        printf("\n"); // new line for next level
    }
}

// Main function
int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter node values (use -1 for NULL):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    levelOrder(root);

    return 0;
}