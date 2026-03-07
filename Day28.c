/*
Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* createCircularList(int n)
{
    if(n == 0)
        return NULL;

    int value;
    Node *head = NULL, *temp = NULL, *prev = NULL;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &value);

        temp = createNode(value);

        if(head == NULL)
        {
            head = temp;
            prev = temp;
        }
        else
        {
            prev->next = temp;
            prev = temp;
        }
    }

    prev->next = head;  // make it circular

    return head;
}

void traverseCircularList(Node* head)
{
    if(head == NULL)
        return;

    Node* temp = head;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } 
    while(temp != head);
}

int main()
{
    int n;
    scanf("%d", &n);

    Node* head = createCircularList(n);

    traverseCircularList(head);

    return 0;
}