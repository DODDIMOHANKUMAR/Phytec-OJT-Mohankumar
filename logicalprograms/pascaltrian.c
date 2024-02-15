#include <stdio.h>

long binomialCoefficient(int n, int r);

void printSpaces(int spaces) {
    for (int i = 0; i < spaces; i++) {
        printf(" ");
    }
}

void generatePascalsTriangle(int numRows) {
    for (int i = 0; i < numRows; i++) {
        // Print spaces to center the triangle
        printSpaces(numRows - i - 1);

        for (int j = 0; j <= i; j++) {
            printf("%ld ", binomialCoefficient(i, j));
        }
        printf("\n");
    }
}

long binomialCoefficient(int n, int r) {
    if (r == 0 || r == n) {
        return 1;
    } else {
        return binomialCoefficient(n - 1, r - 1) + binomialCoefficient(n - 1, r);
    }
}

int main() {
    int numRows;

    // Input the number of rows for Pascal's Triangle
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &numRows);

    // Generate and display Pascal's Triangle in a triangular pattern
    generatePascalsTriangle(numRows);

    return 0;
}

