#include <stdio.h>

int main() {
    int decimal, lsb;

    // Input decimal number
    printf("Enter a Decimal Number: ");
    scanf("%d", &decimal);

    // Calculate the LSB (Least Significant Bit)
    lsb = decimal % 2;

    // Display the LSB
    printf("Least Significant Bit (LSB) of %d is: %d\n", decimal, lsb);

    return 0;
}

