#include <stdio.h>

int main() {
    int rows;

    // Input the number of rows for the reversed triangle
    printf("Enter the number of rows for the reversed triangle: ");
    scanf("%d", &rows);

    // Loop to print the reversed triangle pattern
    for (int i = rows; i >= 1; --i) {
        // Print spaces for each row
        for (int space = 0; space < rows - i; ++space) {
            printf("  ");
        }

        // Print stars for each row
        for (int j = 1; j <= i; ++j) {
            printf("* ");
        }

        // Move to the next line after each row
        printf("\n");
    }

    return 0;
}

