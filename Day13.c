/*Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

Input:
- First line: two integers r and c representing the number of rows and columns
- Next r lines: c integers each representing the matrix elements

Output:
- Print all visited elements in the order of traversal, separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9 */
#include <stdio.h>

int main() {
    
    int r, c;  // Number of rows and columns
    
    // Ask user for matrix size
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);
    
    int matrix[r][c];  // Declare matrix
    
    // Ask user to enter matrix elements
    printf("\nEnter the matrix elements row by row:\n");
    
    for (int i = 0; i < r; i++) {              // Loop through rows
        for (int j = 0; j < c; j++) {          // Loop through columns
            scanf("%d", &matrix[i][j]);        // Store each element
        }
    }
    
    // Print the entered matrix (for clarity)
    printf("\nThe entered matrix is:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Initialize boundaries for spiral traversal
    int top = 0;            // First row index
    int bottom = r - 1;     // Last row index
    int left = 0;           // First column index
    int right = c - 1;      // Last column index
    
    printf("\nSpiral Traversal (Clockwise):\n");
    
    // Continue until all layers are traversed
    while (top <= bottom && left <= right) {
        
        // 1️⃣ Traverse Left → Right (Top Row)
        for (int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++;  // Move top boundary down
        
        // 2️⃣ Traverse Top → Bottom (Right Column)
        for (int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;  // Move right boundary left
        
        // 3️⃣ Traverse Right → Left (Bottom Row)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;  // Move bottom boundary up
        }
        
        // 4️⃣ Traverse Bottom → Top (Left Column)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;  // Move left boundary right
        }
    }
    
    printf("\n");  // Move to next line after output
    
    return 0;  // End program
}