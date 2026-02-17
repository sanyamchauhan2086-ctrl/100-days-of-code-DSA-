/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3*/
#include <stdio.h>

// Function to reverse part of the array
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];     // Store starting element
        arr[start] = arr[end];     // Replace start with end
        arr[end] = temp;           // Put stored value at end
        start++;                   // Move start forward
        end--;                     // Move end backward
    }
}

int main() {
    
    int n;  // Size of array
    
    // Ask user to enter size
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];  // Declare array
    
    // Input array elements
    printf("\nEnter the array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int k;  // Number of rotations
    
    // Ask user to enter k
    printf("\nEnter number of positions to rotate: ");
    scanf("%d", &k);
    
    // Handle cases where k > n
    k = k % n;
    
    // Step 1: Reverse entire array
    reverse(arr, 0, n - 1);
    
    // Step 2: Reverse first k elements
    reverse(arr, 0, k - 1);
    
    // Step 3: Reverse remaining elements
    reverse(arr, k, n - 1);
    
    // Print rotated array
    printf("\nRotated array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    
    return 0;  // End program
}