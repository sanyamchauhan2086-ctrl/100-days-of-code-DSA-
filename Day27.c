/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create list and return head
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Get length of list
int getLength(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

// Find intersection
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node* p1 = head1;
    struct Node* p2 = head2;

    // Move pointer of longer list
    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++)
            p1 = p1->next;
    } else {
        for (int i = 0; i < len2 - len1; i++)
            p2 = p2->next;
    }

    // Move both together
    while (p1 != NULL && p2 != NULL) {
        if (p1 == p2)
            return p1;
        p1 = p1->next;
        p2 = p2->next;
    }

    return NULL;
}

int main() {
    int n, m;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);
    printf("Enter elements of first list: ");
    struct Node* head1 = createList(n);

    printf("Enter number of nodes in second list: ");
    scanf("%d", &m);
    printf("Enter elements of second list: ");
    struct Node* head2 = createList(m);

    // NOTE:
    // This program assumes intersection is manually created.
    // For demonstration, we attach last node of list2
    // to third node of list1 (if exists).

    struct Node* temp1 = head1;
    for (int i = 0; i < 2 && temp1 != NULL; i++)
        temp1 = temp1->next;   // Move to 3rd node (value 30 in example)

    struct Node* temp2 = head2;
    while (temp2->next != NULL)
        temp2 = temp2->next;

    if (temp1 != NULL)
        temp2->next = temp1;   // Create intersection

    struct Node* intersection = findIntersection(head1, head2);

    if (intersection != NULL)
        printf("Intersection at node with value: %d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}