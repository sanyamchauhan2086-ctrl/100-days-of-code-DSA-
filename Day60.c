#include <stdio.h>
#include <stdlib.h>

/*
Day 60 - Question 1: Validate Min-Heap

Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children.
*/

// ----------- STRUCTURE -----------
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// ----------- CREATE NODE -----------
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ----------- BUILD TREE (LEVEL ORDER) -----------
Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    Node* root = createNode(arr[0]);

    Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        Node* current = queue[front++];

        // Left child
        if (i < n) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
            i++;
        }

        // Right child
        if (i < n) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
            i++;
        }
    }

    return root;
}

// ----------- CHECK MIN HEAP -----------
int isMinHeap(Node* root) {
    if (root == NULL) return 1;

    if (root->left != NULL) {
        if (root->data > root->left->data)
            return 0;
    }

    if (root->right != NULL) {
        if (root->data > root->right->data)
            return 0;
    }

    return isMinHeap(root->left) && isMinHeap(root->right);
}

// ----------- MAIN -----------
int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Node* root = buildTree(arr, n);

    if (isMinHeap(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}