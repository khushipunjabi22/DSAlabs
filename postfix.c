#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int top = -1;

int calc(int num1, int num2, char op) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        case '%':
            return num1 % num2;
        default:
            return 0;  
    }
}

int main() {
    char s[100];
    printf("Enter an Expression: ");
    gets(s);

    int length, i = 0;
    length = strlen(s);

    while (i != length) {
        char n = s[i];
        if (n == ' ') {
            i++;
        } else if (n >= '0' && n <= '9') {
            int num = 0;
            while (s[i] != ' ') {
                num = num * 10;
                num = num + (s[i] - '0');
                i++;
            }
            stack[++top] = num;
        } else {
            char op = s[i];
            int n1 = stack[top--];
            int n2 = stack[top--];
            stack[++top] = calc(n2, n1, op);
            i++;
        }
    }

    printf("\nValue of Expression is: %d", stack[top]);
    return 0;
}


