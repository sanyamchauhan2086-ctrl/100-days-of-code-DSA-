/*
Day 49 - Question 1: BST Insert

Problem:
Given a Binary Search Tree (BST), insert a new value into it
while maintaining BST properties.

BST Rule:
- Left subtree → values smaller than root
- Right subtree → values greater than root

Input:
- Enter number of nodes (n)
- Enter n values to insert into BST
- Enter value to insert

Example Input:
5
4 2 7 1 3
5

Output:
BST after insertion (Inorder Traversal):
1 2 3 4 5 7
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

// Insert into BST (recursive)
struct TreeNode* insertBST(struct TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

// Inorder traversal (sorted output)
void inorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Main
int main() {
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct TreeNode* root = NULL;

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insertBST(root, x);
    }

    printf("Enter value to insert: ");
    scanf("%d", &val);

    root = insertBST(root, val);

    printf("\nBST after insertion (Inorder Traversal):\n");
    inorder(root);

    printf("\n");

    return 0;
}