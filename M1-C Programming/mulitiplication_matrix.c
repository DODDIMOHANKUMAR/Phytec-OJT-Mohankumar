#include<stdio.h>

int main() {
    int r, c;
    
    printf("Enter rows and columns:\n");
    scanf("%d %d", &r, &c);

    int mat1[r][c], mat2[r][c], mat3[r][c];

    printf("Enter matrix1:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter matrix2:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Initialize mat3 to zeros
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            mat3[i][j] = 0;
        }
    }

    // Matrix multiplication
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < c; k++) {
                mat3[i][j] = mat3[i][j] + mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("Result Matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", mat3[i][j]);
        }
        printf("\n");
    }

    return 0;
}

