/*
Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. 
Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Sample Input
4 2
10 20 30 40

Sample Output
60
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Helper function with trace logs to check if we can paint boards within 'max_time'
bool isValidAllocation(int boards[], int n, int k, long long max_time) {
    int paintersRequired = 1;
    long long currentSum = 0;
    
    printf("  [Validation] Testing if we can paint with a max limit of %lld time...\n", max_time);
    printf("  [Validation] Painter 1 gets boards: ");

    for (int i = 0; i < n; i++) {
        // If a single board takes more time than the limit, it's impossible
        if (boards[i] > max_time) {
            printf("\n  [Validation] -> FAILED: Board %d (length %d) is larger than the limit %lld.\n", i+1, boards[i], max_time);
            return false;
        }

        // If adding this board exceeds the limit, give it to a new painter
        if (currentSum + boards[i] > max_time) {
            paintersRequired++;
            currentSum = boards[i]; // Start the new painter's count
            
            printf("(Total: %lld)\n", currentSum - boards[i]); // Print previous painter's total
            printf("  [Validation] Limit exceeded! Painter %d gets boards: %d ", paintersRequired, boards[i]);

            // If we need more painters than we have, this limit is too strict
            if (paintersRequired > k) {
                printf("\n  [Validation] -> FAILED: Needed %d painters, but only have %d.\n", paintersRequired, k);
                return false;
            }
        } else {
            // Otherwise, add the board to the current painter's workload
            currentSum += boards[i];
            printf("%d ", boards[i]);
        }
    }
    
    printf("(Total: %lld)\n", currentSum);
    printf("  [Validation] -> SUCCESS: Successfully allocated to %d painter(s).\n", paintersRequired);
    return true;
}

int main() {
    int n, k;
    
    // Read n (boards) and k (painters)
    if (scanf("%d %d", &n, &k) != 2) {
        return 0; // Exit if input fails
    }

    int *boards = (int *)malloc(n * sizeof(int));
    long long totalTime = 0;
    int maxBoard = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        totalTime += boards[i];
        if (boards[i] > maxBoard) {
            maxBoard = boards[i];
        }
    }

    // Step 1: Set up the Binary Search boundaries
    long long low = maxBoard;  // Minimum possible answer (longest single board)
    long long high = totalTime; // Maximum possible answer (one painter paints everything)
    long long best_time = -1;

    printf("\n--- Starting Binary Search on Answer ---\n");
    printf("Initial Bounds: Low = %lld (Longest Board), High = %lld (Sum of all Boards)\n", low, high);

    // Step 2: Binary Search loop
    while (low <= high) {
        long long mid = low + (high - low) / 2; // 'mid' is our guessed max_time limit
        
        printf("\n[Search Step] Low: %lld, High: %lld | Guessed Limit (Mid): %lld\n", low, high, mid);

        if (isValidAllocation(boards, n, k, mid)) {
            printf("[Result] %lld works! Saving as best time so far.\n", mid);
            printf("[Action] Searching left half (High = %lld) to find a tighter limit.\n", mid - 1);
            best_time = mid;
            high = mid - 1; // Try to find a smaller maximum time
        } else {
            printf("[Result] %lld is too strict.\n", mid);
            printf("[Action] Searching right half (Low = %lld) for a larger limit.\n", mid + 1);
            low = mid + 1; // We need to give the painters more time
        }
    }

    printf("\n--- Binary Search Complete ---\n");
    printf("Minimum time required to paint all boards: %lld\n", best_time);

    free(boards);
    return 0;
}