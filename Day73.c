/*
Day 73 - Question 1: First Non-Repeating Character

Problem Statement:
Given a string s consisting of lowercase English letters, find and return
the first character that does not repeat in the string.
If all characters repeat, return '$'.

Input Format:
- A single string s

Output Format:
- Print the first non-repeating character
- If none exists, print '$'

Sample Input:
geeksforgeeks

Sample Output:
f
*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];

    printf("Enter string: ");
    scanf("%s", s);

    int freq[26] = {0};

    printf("\nCounting frequencies...\n");

    // Step 1: Count frequency of each character
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    printf("Frequencies calculated.\n");

    // Step 2: Find first non-repeating character
    printf("\nChecking for first non-repeating character...\n");

    for (int i = 0; s[i] != '\0'; i++) {
        printf("Checking '%c' (count = %d)\n", s[i], freq[s[i] - 'a']);

        if (freq[s[i] - 'a'] == 1) {
            printf("\nFirst non-repeating character: %c\n", s[i]);
            return 0;
        }
    }

    // If all characters repeat
    printf("\n$\n");
    return 0;
}