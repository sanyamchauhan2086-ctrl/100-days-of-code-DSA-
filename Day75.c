/*
Day 75 - Question 1: Largest Subarray with Zero Sum

Problem Statement:
Given an array of integers containing both positive and negative values,
find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format:
- First line: n (size of array)
- Second line: n integers

Output Format:
- Print length of the longest subarray with sum = 0

Sample Input:
8
15 -2 2 -8 1 7 10 23

Sample Output:
5
*/

#include <stdio.h>

#define MAX 1000

int main() {
    int n, arr[MAX];

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maxLen = 0;

    // Brute force approach
    printf("\nChecking all subarrays...\n");

    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum += arr[j];

            printf("Subarray [%d to %d], Sum = %d\n", i, j, sum);

            if (sum == 0) {
                int len = j - i + 1;

                if (len > maxLen) {
                    printf("New longest zero-sum subarray found! Length = %d\n", len);
                    maxLen = len;
                }
            }
        }
    }

    printf("\n===== Result =====\n");
    printf("Length of longest subarray with sum 0: %d\n", maxLen);

    return 0;
}