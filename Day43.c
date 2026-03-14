/*
Problem Statement:
Construct a Binary Tree from the given level-order traversal.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers (-1 represents NULL)

Output Format:
- Print inorder traversal of the constructed tree

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
4 2 5 1 3 6
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

/* Function to create a new node */
Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Inorder traversal */
void inorder(Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    int n;

    printf("Enter number of nodes (max 10 recommended): ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter level-order elements (-1 for NULL):\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    /* Create node pointers array */
    Node* nodes[n];

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    /* Link children according to level order */
    for(int i = 0; i < n; i++)
    {
        if(nodes[i] != NULL)
        {
            int leftIndex = 2*i + 1;
            int rightIndex = 2*i + 2;

            if(leftIndex < n)
                nodes[i]->left = nodes[leftIndex];

            if(rightIndex < n)
                nodes[i]->right = nodes[rightIndex];
        }
    }

    Node* root = nodes[0];

    printf("Inorder Traversal: ");
    inorder(root);

    return 0;
}