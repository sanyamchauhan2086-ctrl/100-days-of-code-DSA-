


/*
Problem:
Check whether a given matrix is symmetric.

A matrix is symmetric if:
1) It is square (m == n)
2) a[i][j] == a[j][i]

Input:
First line: m n
Next m lines: n integers

Output:
"Symmetric Matrix"
or
"Not a Symmetric Matrix"
*/

#include <stdio.h>

int main() {
    int m, n, a[10][10];

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter matrix elements:\n");
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    if(m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] != a[j][i]) {
                printf("Not a Symmetric Matrix");
                return 0;
            }

    printf("Symmetric Matrix");

    return 0;
}
