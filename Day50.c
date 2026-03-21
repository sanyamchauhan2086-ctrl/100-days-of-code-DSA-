/*
Day 50 - Question 1: BST Search

Problem:
Given a Binary Search Tree (BST), search for a value in the tree.
If the value exists, print "Found", otherwise print "Not Found".

BST Rule:
- Left subtree → values smaller than root
- Right subtree → values greater than root

Input:
- Enter number of nodes (n)
- Enter n values to insert into BST
- Enter value to search

Example Input:
5
4 2 7 1 3
2

Output:
Value Found in BST
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

// Search in BST (iterative)
int searchBST(struct TreeNode* root, int key) {
    while (root != NULL) {
        if (root->val == key)
            return 1;
        else if (key < root->val)
            root = root->left;
        else
            root = root->right;
    }
    return 0;
}

// Main
int main() {
    int n, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct TreeNode* root = NULL;

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insertBST(root, x);
    }

    printf("Enter value to search: ");
    scanf("%d", &key);

    int found = searchBST(root, key);

    if (found)
        printf("\nValue Found in BST\n");
    else
        printf("\nValue Not Found in BST\n");

    return 0;
}