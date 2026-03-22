/*
Day 51 - Question 1: Lowest Common Ancestor in BST

Problem:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

BST Rule:
- Left subtree → values smaller than root
- Right subtree → values greater than root

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values (p and q)

Example Input:
7
6 2 8 0 4 7 9
2 8

Output:
LCA: 6
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

// Insert into BST
struct TreeNode* insertBST(struct TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

// Find LCA in BST
struct TreeNode* findLCA(struct TreeNode* root, int p, int q) {
    while (root != NULL) {
        if (p < root->val && q < root->val)
            root = root->left;
        else if (p > root->val && q > root->val)
            root = root->right;
        else
            return root; // split point
    }
    return NULL;
}

// Main
int main() {
    int n, p, q;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct TreeNode* root = NULL;

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insertBST(root, x);
    }

    printf("Enter two node values (p and q): ");
    scanf("%d %d", &p, &q);

    struct TreeNode* lca = findLCA(root, p, q);

    if (lca != NULL)
        printf("\nLCA: %d\n", lca->val);
    else
        printf("\nLCA not found\n");

    return 0;
}