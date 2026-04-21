/*
Day 81 - Question 1: Implement Bubble Sort

Problem:
Implement Bubble Sort algorithm.

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

// Bubble Sort function
void bubbleSort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {

        int swapped = 0;  // optimization

        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                // swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = 1;
            }
        }

        // If no swaps → already sorted
        if (!swapped)
            break;
    }
}

int main() {

    int n;
    printf("Enter number of elements (n): ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}