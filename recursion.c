#include <stdio.h>

// Function to calculate factorial of a number using recursion
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate Fibonacci series using recursion
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    // Factorial
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &n);
    printf("Factorial of %d is: %d\n", n, factorial(n));

    // Fibonacci Series
    printf("\nEnter the number of terms for Fibonacci series: ");
    scanf("%d", &n);
    printf("Fibonacci Series for %d terms is: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}
