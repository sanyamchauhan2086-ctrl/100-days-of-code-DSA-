/*
Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10
*/

#include <stdio.h>

#define MAX 100

/* Queue implementation using array */
int queue[MAX];
int front = 0;
int rear = -1;

/* Stack implementation using array */
int stack[MAX];
int top = -1;

void enqueue(int value)
{
    queue[++rear] = value;
}

int dequeue()
{
    return queue[front++];
}

void push(int value)
{
    stack[++top] = value;
}

int pop()
{
    return stack[top--];
}

int main()
{
    int n;

    printf("Enter number of elements (max 10 recommended): ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    /* Read queue elements */
    for(int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        enqueue(value);
    }

    /* Move elements from queue to stack */
    while(front <= rear)
    {
        push(dequeue());
    }

    /* Move elements back to queue (reversed) */
    front = 0;
    rear = -1;

    while(top != -1)
    {
        enqueue(pop());
    }

    printf("Reversed Queue: ");

    for(int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}