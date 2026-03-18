/*
Day 47 - Question 1: Height of Binary Tree

Problem:
Given a binary tree, find its height (maximum depth).
Height = number of nodes along the longest path from root to leaf.

Input:
- First enter number of nodes (n)
- Then enter node values in level order
- Use -1 for NULL nodes

Example Input:
7
3 9 20 -1 -1 15 7

Output:
Height of Binary Tree: 3
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

// Queue (for building tree)
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
    if (q->rear == q->capacity) return;
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

// Function to calculate height (RECURSIVE)
int height(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return 1 + (left > right ? left : right);
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

    int h = height(root);

    printf("\nHeight of Binary Tree: %d\n", h);

    return 0;
}