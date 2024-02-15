#include <stdio.h>

int main() {
    int num1, num2, sum = 0;

    // Input for the first number
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Input for the second number
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Ensure num1 is less than or equal to num2
    if (num1 > num2) {
        printf("Invalid input: First number should be less than or equal to the second number.\n");
        return 1; // Exit with an error code
    }

    // Calculate the sum of numbers divisible by 5 between num1 and num2
    for (int i = num1; i <= num2; ++i) {
        if (i % 5 == 0) {
            sum += i;
        }
    }

    // Display the result
    printf("Sum of numbers divisible by 5 between %d and %d: %d\n", num1, num2, sum);

    return 0;
}

