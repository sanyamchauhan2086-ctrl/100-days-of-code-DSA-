/*
Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.
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

Node* createList(int n)
{
    Node *head = NULL, *temp = NULL, *prev = NULL;
    int value;

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

    return head;
}

Node* rotateRight(Node* head, int n, int k)
{
    if(head == NULL || k == 0)
        return head;

    Node* temp = head;
    int length = 1;

    while(temp->next != NULL)
    {
        temp = temp->next;
        length++;
    }

    temp->next = head;   // make circular

    k = k % length;
    int steps = length - k;

    Node* newTail = head;

    for(int i = 1; i < steps; i++)
        newTail = newTail->next;

    Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

void printList(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n, k;

    scanf("%d", &n);

    Node* head = createList(n);

    scanf("%d", &k);

    head = rotateRight(head, n, k);

    printList(head);

    return 0;
}