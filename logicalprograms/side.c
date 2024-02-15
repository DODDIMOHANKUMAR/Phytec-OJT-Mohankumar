#include <stdio.h>

int main() {
    int rows;

    // Input the number of rows for the half diamonds
    printf("Enter the number of rows for the half diamonds: ");
    scanf("%d", &rows);

    // Loop to print both half diamond patterns side by side
    for (int i = 1; i <= rows; ++i) {
        // Print spaces for the left side of the first half diamond
        for (int space = 1; space <= rows - i; ++space) {
            printf("  ");
        }

        // Print stars for the left side of the first half diamond
        for (int j = 1; j <= i; ++j) {
            printf("* ");
        }

        // Print spaces between the two half diamonds
        printf("  ");

        // Print stars for the left side of the second half diamond
        for (int j = 1; j <= i; ++j) {
            printf("* ");
        }

        // Move to the next line after each row
        printf("\n");
    }

    return 0;
}

