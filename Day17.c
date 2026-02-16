/*Problem: Write a program to find the maximum and minimum values present in a given array of integers.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the maximum and minimum elements

Example:
Input:
6
3 5 1 9 2 8

Output:
Max: 9
Min: 1*/
#include <stdio.h>

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
    
    // Assume first element is both max and min initially
    int max = arr[0];
    int min = arr[0];
    
    // Traverse array to find max and min
    for (int i = 1; i < n; i++) {
        
        if (arr[i] > max) {   // If current element is greater than max
            max = arr[i];
        }
        
        if (arr[i] < min) {   // If current element is smaller than min
            min = arr[i];
        }
    }
    
    // Print results
    printf("\nMax: %d\n", max);
    printf("Min: %d\n", min);
    
    return 0;  // End program
}