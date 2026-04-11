/*
Day 71 - Question 1: Hash Table Using Quadratic Probing

Problem Statement:
Implement a hash table using quadratic probing with formula:

    h(k, i) = (h(k) + i*i) % m

Where:
- h(k) = k % m (basic hash function)
- i = 0,1,2,... (probe sequence)

Operations:
- INSERT key into hash table
- SEARCH key in hash table

Input Format:
- First line: size of hash table (m)
- Second line: number of operations (q)
- Next q lines: operations (INSERT x / SEARCH x)

Output Format:
- For each SEARCH, print:
    FOUND
    NOT FOUND

Sample Input:
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output:
FOUND
NOT FOUND
*/

#include <stdio.h>
#include <string.h>

#define EMPTY -1
#define MAX 100

int table[MAX];

// Hash function
int hash(int key, int m) {
    return key % m;
}

// Insert using quadratic probing
void insert(int key, int m) {
    int i = 0;
    int index;

    printf("\nInserting %d:\n", key);

    while (i < m) {
        index = (hash(key, m) + i * i) % m;

        printf("Probe i=%d -> index=%d\n", i, index);

        if (table[index] == EMPTY) {
            table[index] = key;
            printf("Inserted %d at index %d\n", key, index);
            return;
        }
        i++;
    }

    printf("Hash Table Overflow! Could not insert %d\n", key);
}

// Search using quadratic probing
void search(int key, int m) {
    int i = 0;
    int index;

    printf("\nSearching %d:\n", key);

    while (i < m) {
        index = (hash(key, m) + i * i) % m;

        printf("Probe i=%d -> index=%d\n", i, index);

        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }

        if (table[index] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }

        i++;
    }

    printf("NOT FOUND\n");
}

int main() {
    int m, q;
    char op[10];
    int key;

    // Initialize table
    for (int i = 0; i < MAX; i++) {
        table[i] = EMPTY;
    }

    printf("Enter hash table size: ");
    scanf("%d", &m);

    printf("Enter number of operations: ");
    scanf("%d", &q);

    printf("\nEnter operations (INSERT x / SEARCH x):\n");

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key, m);
        } else {
            printf("Invalid operation\n");
        }
    }

    return 0;
}