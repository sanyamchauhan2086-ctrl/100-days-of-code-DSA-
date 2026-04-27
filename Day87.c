/*
Day 87 - Question 1: Implement Binary Search Iterative

Problem: Implement Binary Search Iterative - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: target element to search

Output:
- Print sorted array
- Print index of target element (or -1 if not found)

Example:
Input:
5
64 34 25 12 22
25

Output:
12 22 25 34 64
Element found at index: 2
*/

#include <stdio.h>

// Simple sorting (Selection Sort for preparation)
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Binary Search (Iterative)
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    scanf("%d", &target);

    // Step 1: Sort array
    sort(arr, n);

    // Step 2: Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Step 3: Search
    int result = binarySearch(arr, n, target);

    if (result != -1)
        printf("Element found at index: %d", result);
    else
        printf("Element not found");

    return 0;
}