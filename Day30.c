/*
Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coeff;
    int exp;
    struct Node* next;
} Node;

Node* createNode(int coeff, int exp)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

Node* createPolynomial(int n)
{
    Node *head = NULL, *temp = NULL, *prev = NULL;
    int c, e;

    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &c, &e);
        temp = createNode(c, e);

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

void printPolynomial(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        if(temp->exp == 0)
            printf("%d", temp->coeff);
        else if(temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%dx^%d", temp->coeff, temp->exp);

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    Node* head = createPolynomial(n);

    printPolynomial(head);

    return 0;
}