#include<stdio.h>

int main() {
    int i, pos, size, n;
    int arr[8] = {1, 2, 3, 4, 6, 8, 9, 10};

    for (i = 0; i < 8; i++) {
        printf("%d ", arr[i]); 
    }

    pos = 4;
    size = 6;
    n = 8; 

    
    for (i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--; 

    printf("\nArray after deletion:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

