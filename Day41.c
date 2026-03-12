/*
Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue

Example:
Input:
5
enqueue 10
enqueue 20
dequeue
enqueue 30
dequeue

Output:
10
20
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node *front = NULL;
Node *rear = NULL;

/* Enqueue operation */
void enqueue(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if(rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Inserted %d into queue\n", value);
}

/* Dequeue operation */
void dequeue()
{
    if(front == NULL)
    {
        printf("-1\n");
        return;
    }

    Node* temp = front;
    int value = temp->data;

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);

    printf("%d\n", value);
}

int main()
{
    int n, value;
    char op[20];

    printf("Enter number of operations (max 10 recommended): ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("\nEnter operation (enqueue x / dequeue): ");
        scanf("%s", op);

        if(strcmp(op, "enqueue") == 0)
        {
            scanf("%d", &value);
            enqueue(value);
        }
        else if(strcmp(op, "dequeue") == 0)
        {
            dequeue();
        }
        else
        {
            printf("Invalid operation\n");
        }
    }

    return 0;
}