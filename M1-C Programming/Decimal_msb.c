#include <stdio.h>

int getMSB(int decimalNumber) {
    // Assuming int is 32 bits
    int msbPosition = sizeof(int) * 8 - 1;

    // Shift the MSB to the least significant bit and mask the rest
    return (decimalNumber >> msbPosition) & 1;
}

int main() {
    int decimalNumber;

    // Input decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    // Display MSB
    printf("MSB of %d is %d\n", decimalNumber, getMSB(decimalNumber));

    return 0;
}

