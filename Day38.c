/*
Problem: Deque (Double-Ended Queue)

A Deque allows insertion and deletion from both front and rear.

Operations implemented:
1. push_front
2. push_back
3. pop_front
4. pop_back
5. front
6. back
7. size
8. display

Note:
Program allows up to 10 operations for testing.
*/

#include <stdio.h>

#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

int isEmpty()
{
    return front == -1;
}

void push_front(int value)
{
    if(front == 0)
    {
        printf("Deque Overflow\n");
        return;
    }

    if(isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        front--;
    }

    deque[front] = value;
    printf("%d inserted at front\n", value);
}

void push_back(int value)
{
    if(rear == MAX-1)
    {
        printf("Deque Overflow\n");
        return;
    }

    if(isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = value;
    printf("%d inserted at rear\n", value);
}

void pop_front()
{
    if(isEmpty())
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed from front: %d\n", deque[front]);

    if(front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back()
{
    if(isEmpty())
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed from rear: %d\n", deque[rear]);

    if(front == rear)
        front = rear = -1;
    else
        rear--;
}

void getFront()
{
    if(isEmpty())
        printf("Deque is empty\n");
    else
        printf("Front element: %d\n", deque[front]);
}

void getRear()
{
    if(isEmpty())
        printf("Deque is empty\n");
    else
        printf("Rear element: %d\n", deque[rear]);
}

void display()
{
    if(isEmpty())
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");

    for(int i = front; i <= rear; i++)
        printf("%d ", deque[i]);

    printf("\n");
}

int size()
{
    if(isEmpty())
        return 0;

    return rear - front + 1;
}

int main()
{
    int operations, choice, value;

    printf("Enter number of operations (max 10): ");
    scanf("%d", &operations);

    if(operations > 10)
        operations = 10;

    for(int i = 0; i < operations; i++)
    {
        printf("\nChoose operation:\n");
        printf("1 push_front\n");
        printf("2 push_back\n");
        printf("3 pop_front\n");
        printf("4 pop_back\n");
        printf("5 front\n");
        printf("6 back\n");
        printf("7 size\n");
        printf("8 display\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push_front(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                push_back(value);
                break;

            case 3:
                pop_front();
                break;

            case 4:
                pop_back();
                break;

            case 5:
                getFront();
                break;

            case 6:
                getRear();
                break;

            case 7:
                printf("Deque size: %d\n", size());
                break;

            case 8:
                display();
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}