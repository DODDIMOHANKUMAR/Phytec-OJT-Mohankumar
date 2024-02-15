#include <stdio.h>

int main() {
    int rows, cols;

    // Getting user input for the number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Declare a matrix of size rows x cols
    int matrix[rows][cols];

    // Getting user input for the matrix elements
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate the sum of elements in the lower triangle
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i >= j) {
                sum += matrix[i][j];
            }
        }
    }

    // Print the result
    printf("Sum of elements in the lower triangle: %d\n", sum);

    return 0;
}

