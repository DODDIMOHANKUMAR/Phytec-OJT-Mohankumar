#include <stdio.h>

int main() {
    int decimal, n, bit;

    // Input decimal number
    printf("Enter a Decimal Number: ");
    scanf("%d", &decimal);

    // Input the bit position (0-based indexing)
    printf("Enter the Bit Position (N): ");
    scanf("%d", &n);

    // Calculate the Nth bit using bitwise AND with 1 shifted to the Nth position
    bit = (decimal >> n) & 1;

    // Display the result
    printf("The %dth bit of %d is: %d\n", n, decimal, bit);

    return 0;
}

