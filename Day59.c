#include <stdio.h>
#include <stdlib.h>

/*
Day 59 - Question 1: Build Tree from Inorder & Postorder

Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.
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
Node* build(int inorder[], int inStart, int inEnd,
            int postorder[], int postStart, int postEnd) {

    if (inStart > inEnd || postStart > postEnd)
        return NULL;

    // Root from postorder (last element)
    int rootVal = postorder[postEnd];
    Node* root = createNode(rootVal);

    // Find root in inorder
    int k = inStart;
    while (inorder[k] != rootVal) k++;

    int leftSize = k - inStart;

    // Build left subtree
    root->left = build(inorder, inStart, k - 1,
                       postorder, postStart, postStart + leftSize - 1);

    // Build right subtree
    root->right = build(inorder, k + 1, inEnd,
                        postorder, postStart + leftSize, postEnd - 1);

    return root;
}

// ----------- PREORDER TRAVERSAL -----------
void preorder(Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// ----------- MAIN -----------
int main() {
    int n;
    scanf("%d", &n);

    int inorder[1000], postorder[1000];

    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }

    Node* root = build(inorder, 0, n - 1, postorder, 0, n - 1);

    preorder(root);

    return 0;
}