/*
Day 74 - Question 1: Winner of an Election

Problem Statement:
Given an array of candidate names where each name represents a vote cast
for that candidate, determine the candidate who received the maximum number
of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format:
- First line: integer n (number of votes)
- Second line: n space-separated candidate names

Output Format:
- Print: <winner_name> <vote_count>

Sample Input:
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output:
john 4
*/

#include <stdio.h>
#include <string.h>

#define MAX 1000
#define NAME_LEN 50

int main() {
    int n;

    printf("Enter number of votes: ");
    scanf("%d", &n);

    char votes[MAX][NAME_LEN];

    printf("Enter candidate names:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    char unique[MAX][NAME_LEN];
    int count[MAX] = {0};
    int uniqueCount = 0;

    // Count votes
    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(votes[i], unique[j]) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(unique[uniqueCount], votes[i]);
            count[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    // Find winner
    int maxVotes = -1;
    char winner[NAME_LEN];

    for (int i = 0; i < uniqueCount; i++) {
        printf("Candidate: %s, Votes: %d\n", unique[i], count[i]);

        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, unique[i]);
        }
        else if (count[i] == maxVotes) {
            // Lexicographically smaller check
            if (strcmp(unique[i], winner) < 0) {
                strcpy(winner, unique[i]);
            }
        }
    }

    printf("\nWinner: %s %d\n", winner, maxVotes);

    return 0;
}