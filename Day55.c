/*
Day 55 - Question 1: Right View of Binary Tree

Problem:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Example Input:
7
1 2 3 4 5 -1 6

Output:
Right View:
1 3 6
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

// Queue
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

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->arr[q->rear++] = node;
    q->size++;
}

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

// Right View Function
void rightView(struct TreeNode* root, int n) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    struct Queue* q = createQueue(n);
    enqueue(q, root);

    printf("\nRight View:\n");

    while (!isEmpty(q)) {
        int levelSize = q->size;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(q);

            // Last node of each level
            if (i == levelSize - 1) {
                printf("%d ", node->val);
            }

            if (node->left)
                enqueue(q, node->left);
            if (node->right)
                enqueue(q, node->right);
        }
    }

    printf("\n");
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

    rightView(root, n);

    return 0;
}