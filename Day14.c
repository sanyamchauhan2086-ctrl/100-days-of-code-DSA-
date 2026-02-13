/*Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

Input:
- First line: integer n representing number of rows and columns
- Next n lines: n integers each representing the matrix elements

Output:
- Print "Identity Matrix" if the matrix satisfies the condition
- Otherwise, print "Not an Identity Matrix"

Example:
Input:
3
1 0 0
0 1 0
0 0 1

Output:
Identity Matrix*/
#include <stdio.h>

int main() {
    
    int n;  // Size of square matrix
    
    // Ask user to enter size
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);
    
    int matrix[n][n];  // Declare n x n matrix
    
    // Ask user to enter matrix elements
    printf("\nEnter the matrix elements row by row:\n");
    
    for (int i = 0; i < n; i++) {              // Loop through rows
        for (int j = 0; j < n; j++) {          // Loop through columns
            scanf("%d", &matrix[i][j]);        // Store each element
        }
    }
    
    // Print the entered matrix (for clarity)
    printf("\nThe entered matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    int isIdentity = 1;  // Assume matrix is identity initially
    
    // Check identity condition
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            if (i == j) {  
                // Diagonal elements must be 1
                if (matrix[i][j] != 1) {
                    isIdentity = 0;
                }
            } 
            else {  
                // Non-diagonal elements must be 0
                if (matrix[i][j] != 0) {
                    isIdentity = 0;
                }
            }
        }
    }
    
    // Print result
    if (isIdentity == 1) {
        printf("\nIdentity Matrix\n");
    } else {
        printf("\nNot an Identity Matrix\n");
    }
    
    return 0;  // End program
}