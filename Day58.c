#include <stdio.h>
#include <stdlib.h>

/*
Day 58 - Question 1: Build Tree from Inorder & Preorder

Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees.
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

// ----------- BUILD TREE FUNCTION -----------
Node* build(int preorder[], int preStart, int preEnd,
            int inorder[], int inStart, int inEnd) {

    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    // Root from preorder
    int rootVal = preorder[preStart];
    Node* root = createNode(rootVal);

    // Find root in inorder
    int k = inStart;
    while (inorder[k] != rootVal) k++;

    int leftSize = k - inStart;

    // Build left subtree
    root->left = build(preorder, preStart + 1, preStart + leftSize,
                       inorder, inStart, k - 1);

    // Build right subtree
    root->right = build(preorder, preStart + leftSize + 1, preEnd,
                        inorder, k + 1, inEnd);

    return root;
}

// ----------- POSTORDER TRAVERSAL -----------
void postorder(Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// ----------- MAIN -----------
int main() {
    int n;
    scanf("%d", &n);

    int preorder[1000], inorder[1000];

    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    Node* root = build(preorder, 0, n - 1, inorder, 0, n - 1);

    postorder(root);

    return 0;
}