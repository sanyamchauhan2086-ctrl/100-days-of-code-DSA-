/*roblem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array.
For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3].
 Since there are 6 such subarrays, the output is 6.*/

 #include <stdio.h>
#include <stdlib.h>

// Simple hash map using arrays (since constraints not specified large)
#define MAX 100000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long prefixSum = 0;
    long long count = 0;

    // Since prefix sum can be negative, shift index
    // Using offset method
    int size = 2 * MAX + 1;
    long long *freq = (long long*)calloc(size, sizeof(long long));

    int offset = MAX;

    // Initialize: prefix sum 0 appears once
    freq[offset] = 1;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if(freq[prefixSum + offset] > 0) {
            count += freq[prefixSum + offset];
        }

        freq[prefixSum + offset]++;
    }

    printf("%lld\n", count);

    free(freq);
    return 0;
}