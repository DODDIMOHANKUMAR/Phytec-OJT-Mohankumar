#include <stdio.h>

int main() {
    int rows;

    // Input the number of rows for the left-side below half triangle
    printf("Enter the number of rows for the left-side below half triangle: ");
    scanf("%d", &rows);

    // Loop to print the left-side below half triangle pattern
    for (int i = 1; i <= rows; ++i) {
        // Print stars for each row
        for (int j = 1; j <= i; ++j) {
            printf("* ");
        }

        // Move to the next line after each row
        printf("\n");
    }

    return 0;
}

