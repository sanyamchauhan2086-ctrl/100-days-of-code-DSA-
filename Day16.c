/*Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count

Example:
Input:
5
1 2 2 3 1

Output:
1:2 2:2 3:1*/
#include <stdio.h>

int main() {
    
    int n;  // Size of array
    
    // Ask user to enter size
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];      // Declare array
    int visited[n];  // Array to mark counted elements
    
    // Initialize visited array to 0
    for (int i = 0; i < n; i++) {
        visited[i] = 0;   // 0 means not counted yet
    }
    
    // Input array elements
    printf("\nEnter the array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nFrequency of each element:\n");
    
    // Count frequency
    for (int i = 0; i < n; i++) {
        
        if (visited[i] == 1)  // Skip if already counted
            continue;
        
        int count = 1;  // Start counting from 1
        
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;          // Increase count
                visited[j] = 1;   // Mark as counted
            }
        }
        
        // Print result in required format
        printf("%d:%d ", arr[i], count);
    }
    
    printf("\n");
    
    return 0;  // End program
}