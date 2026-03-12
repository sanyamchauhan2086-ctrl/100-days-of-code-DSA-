/*
Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    if(top == -1)
        return '\0';
    return stack[top--];
}

char peek()
{
    if(top == -1)
        return '\0';
    return stack[top];
}

int precedence(char c)
{
    if(c == '+' || c == '-')
        return 1;
    if(c == '*' || c == '/')
        return 2;
    if(c == '^')
        return 3;
    return 0;
}

int main()
{
    char infix[MAX], postfix[MAX];
    int j = 0;

    scanf("%s", infix);

    for(int i = 0; i < strlen(infix); i++)
    {
        char c = infix[i];

        if(isalnum(c))
        {
            postfix[j++] = c;
        }
        else if(c == '(')
        {
            push(c);
        }
        else if(c == ')')
        {
            while(peek() != '(')
                postfix[j++] = pop();
            pop();
        }
        else
        {
            while(top != -1 && precedence(peek()) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }

    while(top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("%s", postfix);

    return 0;
}