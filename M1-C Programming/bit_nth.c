#include <stdio.h>

int getNthBit(int decimalNumber, int n) {
    // Shift the bit of interest to the least significant bit and mask the rest
    return (decimalNumber >> n) & 1;
}

int main() {
    int decimalNumber, n;

    // Input decimal number and bit position
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    printf("Enter the bit position (0-based): ");
    scanf("%d", &n);

    // Display the Nth bit
    printf("Bit at position %d of %d is %d\n", n, decimalNumber, getNthBit(decimalNumber, n));

    return 0;
}
[
