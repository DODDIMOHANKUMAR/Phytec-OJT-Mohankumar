#include <stdio.h>

// Function to calculate factorial of a number
int factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

int main() {
    int n;

    // Input the value of n
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Calculate and print the sum of the series
    double sum = 0.0;
    for (int i = 1; i <= n; ++i) {
        sum += (double)factorial(i) / i;
    }

    printf("Sum of the series: %.2lf\n", sum);

    return 0;
}

