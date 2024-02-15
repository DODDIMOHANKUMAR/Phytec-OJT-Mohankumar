#include <stdio.h>

int getLSB(int decimalNumber) {
    // Extract LSB using bitwise AND
    return decimalNumber & 1;
}

int main() {
    int decimalNumber;

    // Input decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    // Display LSB
    printf("LSB of %d is %d\n", decimalNumber, getLSB(decimalNumber));

    return 0;
}


