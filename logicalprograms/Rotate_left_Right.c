#include <stdio.h>

// Function to rotate left
unsigned int rotateLeft(unsigned int num, int positions) {
    return (num << positions) | (num >> (32 - positions));
}

// Function to rotate right
unsigned int rotateRight(unsigned int num, int positions) {
    return (num >> positions) | (num << (32 - positions));
}

int main() {
    unsigned int number, rotatedNumber;
    int positions;

    // Input the number
    printf("Enter a number: ");
    scanf("%u", &number);

    // Input the number of positions to rotate
    printf("Enter the number of positions to rotate: ");
    scanf("%d", &positions);

    // Perform left rotation
    rotatedNumber = rotateLeft(number, positions);
    printf("Number after left rotation: %u\n", rotatedNumber);

    // Perform right rotation
    rotatedNumber = rotateRight(number, positions);
    printf("Number after right rotation: %u\n", rotatedNumber);

    return 0;
}

