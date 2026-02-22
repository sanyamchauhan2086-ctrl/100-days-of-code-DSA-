/*Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

Input:
- First line: two integers m and n
- Next m lines: n integers each

Output:
- Print the sum of the primary diagonal elements

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
15

Explanation:
1 + 5 + 9 = 15*/
#include <stdio.h>

int main() {
    
    int m, n;   // m = rows, n = columns
    
    // Ask user to enter matrix size
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);
    
    int matrix[m][n];   // Declare matrix
    
    // Ask user to enter matrix elements
    printf("\nEnter the matrix elements row by row:\n");
    
    for (int i = 0; i < m; i++) {            // Loop through rows
        for (int j = 0; j < n; j++) {        // Loop through columns
            scanf("%d", &matrix[i][j]);      // Store each element
        }
    }
    
    // Print the entered matrix (for clarity)
    printf("\nThe entered matrix is:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    int sum = 0;   // Variable to store diagonal sum
    
    // Calculate primary diagonal sum
    for (int i = 0; i < m && i < n; i++) {
        sum += matrix[i][i];   // Add elements where row index == column index
    }
    
    // Print result
    printf("\nSum of primary diagonal elements = %d\n", sum);
    
    return 0;   // End program
}