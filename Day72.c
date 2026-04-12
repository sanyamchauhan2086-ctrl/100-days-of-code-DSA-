/*
Day 72 - Question 1: First Repeated Character

Problem Statement:
Given a string s consisting of lowercase letters, find the first repeated
character in the string. A character is considered repeated if it appears
more than once, and among all such characters, the one whose second
occurrence has the smallest index should be returned.

Input Format:
- A single string s

Output Format:
- Print the first repeated character
- If no character is repeated, print -1

Sample Input:
geeksforgeeks

Sample Output:
e
*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];

    printf("Enter string: ");
    scanf("%s", s);

    // Frequency array for 26 lowercase letters
    int visited[26] = {0};

    printf("\nProcessing string...\n");

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        printf("Checking character '%c' at index %d\n", s[i], i);

        if (visited[index] == 1) {
            printf("\nFirst repeated character: %c\n", s[i]);
            return 0;
        }

        visited[index] = 1;
    }

    printf("\n-1\n");
    return 0;
}