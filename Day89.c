/*
Problem Statement
Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Helper function with trace logs to check if we can allocate books
bool isValidAllocation(int books[], int n, int m, int max_pages) {
    int studentsRequired = 1;
    int currentSum = 0;
    
    printf("  [Validation] Testing if we can allocate with a max limit of %d pages...\n", max_pages);
    printf("  [Validation] Student 1 gets books: ");

    for (int i = 0; i < n; i++) {
        // If a single book has more pages than the limit, it's impossible
        if (books[i] > max_pages) {
            printf("\n  [Validation] -> FAILED: Book %d (%d pages) is larger than the limit %d.\n", i+1, books[i], max_pages);
            return false;
        }

        // If adding this book exceeds the limit, give it to a new student
        if (currentSum + books[i] > max_pages) {
            studentsRequired++;
            currentSum = books[i]; // Start the new student's count
            
            printf("(Total: %d)\n", currentSum - books[i]); // Print previous student total
            printf("  [Validation] Limit exceeded! Student %d gets books: %d ", studentsRequired, books[i]);

            // If we need more students than we have, this limit is too strict
            if (studentsRequired > m) {
                printf("\n  [Validation] -> FAILED: Needed %d students, but only have %d.\n", studentsRequired, m);
                return false;
            }
        } else {
            // Otherwise, add the book to the current student's pile
            currentSum += books[i];
            printf("%d ", books[i]);
        }
    }
    
    printf("(Total: %d)\n", currentSum);
    printf("  [Validation] -> SUCCESS: Successfully allocated to %d student(s).\n", studentsRequired);
    return true;
}

int main() {
    int n, m;
    
    // Read n (books) and m (students)
    if (scanf("%d %d", &n, &m) != 2) {
        return 0; // Exit if input fails
    }

    int *books = (int *)malloc(n * sizeof(int));
    int totalPages = 0;
    int maxBook = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
        totalPages += books[i];
        if (books[i] > maxBook) {
            maxBook = books[i];
        }
    }

    // Edge case: More students than books
    if (m > n) {
        printf("\nResult: -1 (More students than books)\n");
        free(books);
        return 0;
    }

    int low = maxBook;     
    int high = totalPages; 
    int best_allocation = -1;

    printf("\n--- Starting Binary Search on Answer ---\n");
    printf("Initial Bounds: Low = %d (Largest Book), High = %d (Sum of all Books)\n", low, high);

    while (low <= high) {
        int mid = low + (high - low) / 2; 
        
        printf("\n[Search Step] Low: %d, High: %d | Guessed Limit (Mid): %d\n", low, high, mid);

        if (isValidAllocation(books, n, m, mid)) {
            printf("[Result] %d works! Saving as best answer so far.\n", mid);
            printf("[Action] Searching left half (High = %d) to find a tighter limit.\n", mid - 1);
            best_allocation = mid;
            high = mid - 1; 
        } else {
            printf("[Result] %d is too strict.\n", mid);
            printf("[Action] Searching right half (Low = %d) for a larger limit.\n", mid + 1);
            low = mid + 1;
        }
    }

    printf("\n--- Binary Search Complete ---\n");
    printf("Minimum possible value of the maximum pages: %d\n", best_allocation);

    free(books);
    return 0;
}