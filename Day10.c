// C program to check if a given string is a palindrome
#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    
    // Read string (no spaces as per normal basic input)
    scanf("%s", str);

    int left = 0;
    int right = strlen(str) - 1;

    int isPalindrome = 1;  // assume true

    while (left < right) {
        if (str[left] != str[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome)
        printf("Palindrome");
    else
        printf("Not Palindrome");

    return 0;
}
