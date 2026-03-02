/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create linked list
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

// Print list
void printList(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" ");
        temp = temp->next;
    }
    printf("\n");
}

// Merge two sorted lists
struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    if (head1 != NULL)
        tail->next = head1;
    else
        tail->next = head2;

    return dummy.next;
}

int main() {
    int n, m;

    printf("Enter number of elements in first list: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements: ", n);
    struct Node* head1 = createList(n);

    printf("Enter number of elements in second list: ");
    scanf("%d", &m);

    printf("Enter %d sorted elements: ", m);
    struct Node* head2 = createList(m);

    printf("\nFirst Linked List: ");
    printList(head1);

    printf("Second Linked List: ");
    printList(head2);

    struct Node* mergedHead = mergeLists(head1, head2);

    printf("Merged Linked List: ");
    printList(mergedHead);

    return 0;
}