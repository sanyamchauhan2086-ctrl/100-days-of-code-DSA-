/*
Day 52 - Question 1: LCA in Binary Tree

Problem:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

NOTE:
This is NOT a BST → cannot use value comparisons.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values (p and q)

Example Input:
7
1 2 3 4 5 6 7
4 5

Output:
LCA: 2
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
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue for building tree
struct Queue {
    struct TreeNode** arr;
    int front, rear, size;
};

// Create queue
struct Queue* createQueue(int n) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * n);
    q->front = q->rear = q->size = 0;
    return q;
}

// Check empty
int isEmpty(struct Queue* q) {
    return q->size == 0;
}

// Enqueue
void enqueue(struct Queue* q, struct TreeNode* node) {
    q->arr[q->rear++] = node;
    q->size++;
}

// Dequeue
struct TreeNode* dequeue(struct Queue* q) {
    q->size--;
    return q->arr[q->front++];
}

// Build tree from level order
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

// LCA in Binary Tree (recursive)
struct TreeNode* findLCA(struct TreeNode* root, int p, int q) {
    if (root == NULL)
        return NULL;

    if (root->val == p || root->val == q)
        return root;

    struct TreeNode* left = findLCA(root->left, p, q);
    struct TreeNode* right = findLCA(root->right, p, q);

    if (left != NULL && right != NULL)
        return root;

    return (left != NULL) ? left : right;
}

// Main
int main() {
    int n, p, q;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter level order values (-1 for NULL):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    printf("Enter two node values (p and q): ");
    scanf("%d %d", &p, &q);

    struct TreeNode* lca = findLCA(root, p, q);

    if (lca != NULL)
        printf("\nLCA: %d\n", lca->val);
    else
        printf("\nLCA not found\n");

    return 0;
}