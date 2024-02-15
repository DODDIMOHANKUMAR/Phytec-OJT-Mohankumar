#include <stdio.h>

// Structure to represent a complex number
struct Complex {
    float real;
    float imaginary;
};

int main() {
    struct Complex complex1, complex2;

    // Input for the first complex number
    printf("Enter the real part of the first complex number: ");
    scanf("%f", &complex1.real);

    printf("Enter the imaginary part of the first complex number: ");
    scanf("%f", &complex1.imaginary);

    // Input for the second complex number
    printf("Enter the real part of the second complex number: ");
    scanf("%f", &complex2.real);

    printf("Enter the imaginary part of the second complex number: ");
    scanf("%f", &complex2.imaginary);

    // Displaying the entered complex numbers
    printf("\nFirst Complex Number: %.2f + %.2fi\n", complex1.real, complex1.imaginary);
    printf("Second Complex Number: %.2f + %.2fi\n", complex2.real, complex2.imaginary);

    return 0;
}

