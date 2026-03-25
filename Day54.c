/*
Day 54 - Question 1: Zigzag Traversal (FINAL SAFE VERSION)

Problem:
Perform zigzag (spiral) level order traversal of a binary tree.

Input:
- First line: N
- Second line: level order (-1 for NULL)

Output:
- Zigzag traversal

Example:
Input:
7
1 2 3 4 5 6 7

Output:
Zigzag Traversal:
1 3 2 4 5 6 7
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

// Circular Queue
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

int isEmpty(struct Queue* q) {
    return q->size == 0;
}

int isFull(struct Queue* q) {
    return q->size == q->capacity;
}

// Enqueue (safe)
void enqueue(struct Queue* q, struct TreeNode* node) {
    if (isFull(q)) return;

    q->arr[q->rear] = node;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
}

// Dequeue
struct TreeNode* dequeue(struct Queue* q) {
    struct TreeNode* node = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return node;
}

// Build tree
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode* root = createNode(arr[0]);

    struct Queue* q = createQueue(n);
    enqueue(q, root);

    int i = 1;

    while (!isEmpty(q) && i < n) {
        struct TreeNode* curr = dequeue(q);

        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(q, curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(q, curr->right);
        }
        i++;
    }

    return root;
}

// Zigzag Traversal
void zigzagTraversal(struct TreeNode* root, int n) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    struct Queue* q = createQueue(n);
    enqueue(q, root);

    int leftToRight = 1;

    printf("\nZigzag Traversal:\n");

    while (!isEmpty(q)) {
        int levelSize = q->size;

        // Safe dynamic array
        int* level = (int*)malloc(sizeof(int) * levelSize);

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(q);

            int index = leftToRight ? i : (levelSize - 1 - i);
            level[index] = node->val;

            if (node->left)
                enqueue(q, node->left);
            if (node->right)
                enqueue(q, node->right);
        }

        // Print level
        for (int i = 0; i < levelSize; i++) {
            printf("%d ", level[i]);
        }

        free(level); // prevent memory leak
        leftToRight = !leftToRight;
    }

    printf("\n");
}

// Main
int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(sizeof(int) * n);

    printf("Enter level order values (-1 for NULL):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    zigzagTraversal(root, n);

    free(arr);

    return 0;
}