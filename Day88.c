/*
Problem Statement
Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the minimum distance between any two cows is maximized.

This is an optimization problem where binary search on the answer is required.

Input Format
n k
n space-separated integers representing stall positions

Output Format
Print the maximum possible minimum distance between any two cows.

Sample Input
5 3
1 2 8 4 9

Sample Output
3

Explanation
Cows can be placed at positions 1, 4, and 8. The minimum distance between any two cows is 3, which is the maximum possible.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Helper function to check if we can place 'k' cows with at least 'dist' gap
bool canPlaceCows(int stalls[], int n, int k, int dist) {
    int cowsPlaced = 1; // Always place the first cow in the first stall
    int lastPlaced = stalls[0];

    for (int i = 1; i < n; i++) {
        // If the current stall is far enough from the last placed cow
        if (stalls[i] - lastPlaced >= dist) {
            cowsPlaced++;
            lastPlaced = stalls[i];
            
            // If we successfully placed all k cows, this distance works
            if (cowsPlaced == k) {
                return true;
            }
        }
    }
    // We ran out of stalls before placing all k cows
    return false;
}

int main() {
    int n, k;
    
    // Read n and k
    if (scanf("%d %d", &n, &k) != 2) {
        return 0; // Exit if input fails
    }

    // Allocate memory for the stalls
    int *stalls = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // Step 1: Sort the stalls array
    // Binary search only works if the stalls are in linear order
    qsort(stalls, n, sizeof(int), compare);

    // Step 2: Binary Search on the Answer
    int low = 1; // Minimum possible gap
    int high = stalls[n - 1] - stalls[0]; // Maximum possible gap
    int best_distance = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if it is possible to maintain a minimum gap of 'mid'
        if (canPlaceCows(stalls, n, k, mid)) {
            best_distance = mid; // It's possible, save the answer
            low = mid + 1;       // Try to find a LARGER minimum gap
        } else {
            high = mid - 1;      // It's impossible, we must reduce the gap
        }
    }

    // Output the result
    printf("%d\n", best_distance);

    // Clean up memory
    free(stalls);
    return 0;
}
