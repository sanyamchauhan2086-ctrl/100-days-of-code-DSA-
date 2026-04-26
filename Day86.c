/*
Day 86 - Question 1: Square Root using Binary Search

Problem: Find the integer square root of a given non-negative integer using Binary Search.
The integer square root of a number is defined as the greatest integer whose square is
less than or equal to the given number.

Input:
- First line: an integer n

Output:
- Print the integer square root of n

Examples:
Input:
64
Output:
8

Input:
20
Output:
4

Input:
1
Output:
1
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    // Edge cases
    if (n == 0 || n == 1) {
        printf("%d", n);
        return 0;
    }

    int left = 1;
    int right = n;
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Avoid overflow using division
        if (mid <= n / mid) {
            ans = mid;          // valid candidate
            left = mid + 1;     // try larger value
        } else {
            right = mid - 1;    // go smaller
        }
    }

    printf("%d", ans);
    return 0;
}