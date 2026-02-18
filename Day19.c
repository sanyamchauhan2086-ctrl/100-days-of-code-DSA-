/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.*/
#include <stdio.h>
#include <stdlib.h>   // For abs()

// Function to compare integers for sorting (used by qsort)
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    
    int n;   // Size of array
    
    // Ask user to enter size
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    if (n < 2) {
        printf("At least two elements are required.\n");
        return 0;
    }
    
    int arr[n];  // Declare array
    
    // Input array elements
    printf("\nEnter the array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Sort the array
    qsort(arr, n, sizeof(int), compare);
    
    int left = 0;          // Start pointer
    int right = n - 1;     // End pointer
    
    int minSum = arr[left] + arr[right];
    int minLeft = arr[left];
    int minRight = arr[right];
    
    // Two-pointer approach
    while (left < right) {
        
        int sum = arr[left] + arr[right];
        
        // Update minimum sum if current is closer to zero
        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            minLeft = arr[left];
            minRight = arr[right];
        }
        
        // Move pointers
        if (sum < 0)
            left++;   // Increase sum
        else
            right--;  // Decrease sum
    }
    
    // Print result
    printf("\nPair with sum closest to zero:\n");
    printf("%d %d\n", minLeft, minRight);
    
    return 0;
}