#include <stdio.h>

// Function to calculate the determinant of a 3x3 matrix
double calculateDeterminant(int matrix[3][3]) {
    double det;

    det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
        - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
        + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);

    return det;
}

int main() {
    int matrix[3][3];

    // Getting user input for the matrix elements
    printf("Enter the elements of the 3x3 matrix:\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculating and printing the determinant
    double determinant = calculateDeterminant(matrix);
    printf("Determinant of the matrix: %.2f\n", determinant);

    return 0;
}

