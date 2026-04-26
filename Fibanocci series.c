Aim:
To implement a recursive function in C to find the nth Fibonacci number using recursion
#include <stdio.h>

// Function to calculate nth Fibonacci number using recursion
int fib(int n){  
    // Base case: fib(0) = 0
    if (n == 0){
        return 0;
    }

    // Base case: fib(1) = 1
    if (n == 1) {
        return 1;
    }

    // Recursive case:
    // fib(n) = fib(n-1) + fib(n-2)
    return fib(n-1) + fib(n-2);
}  

int main() {
    int n;

    // Take input from user
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Check for invalid input
    if (n < 0){
        printf("Invalid number");
        return 0;
    }

    // Display the nth Fibonacci number
    printf("Fibonacci term is: %d", fib(n));

    return 0;
}
