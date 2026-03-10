/*
Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int heap[MAX];
int size = 0;

/* Swap two elements */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify up (used after insertion) */
void heapifyUp(int index)
{
    while(index > 0)
    {
        int parent = (index - 1) / 2;

        if(heap[parent] <= heap[index])
            break;

        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

/* Heapify down (used after extractMin) */
void heapifyDown(int index)
{
    while(1)
    {
        int left = 2*index + 1;
        int right = 2*index + 2;
        int smallest = index;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest == index)
            break;

        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}

/* Insert operation */
void insert(int value)
{
    if(size == MAX)
    {
        printf("Heap Overflow\n");
        return;
    }

    heap[size] = value;
    heapifyUp(size);
    size++;

    printf("Inserted %d into heap\n", value);
}

/* Peek operation */
void peek()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);
}

/* Extract minimum element */
void extractMin()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);
}

int main()
{
    int n, value;
    char op[20];

    printf("Enter number of operations (max 10 recommended): ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("\nEnter operation (insert x / extractMin / peek): ");
        scanf("%s", op);

        if(strcmp(op, "insert") == 0)
        {
            scanf("%d", &value);
            insert(value);
        }
        else if(strcmp(op, "extractMin") == 0)
        {
            extractMin();
        }
        else if(strcmp(op, "peek") == 0)
        {
            peek();
        }
        else
        {
            printf("Invalid operation\n");
        }
    }

    return 0;
}