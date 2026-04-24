/*
Day 84 - Question 1: Implement Insertion Sort

Problem: Implement Insertion Sort - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array

Example:
Input:
5
64 34 25 12 22

Output:
12 22 25 34 64
*/

#include <stdio.h>

int main() {
    int n;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Insertion Sort
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert key at correct position
        arr[j + 1] = key;
    }

    // Output sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}