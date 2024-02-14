#include<stdio.h>

int main() {
    int n, count, duplicate = 0;

    int arr[] = {1, 2, 2, 3, 4, 4, 5, 6, 7, 8, 9};
    n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1] && arr[i] != duplicate) {
            duplicate = arr[i];
            count = 2; // Initialize count for the first occurrence

            // Count additional occurrences
            while (i + count < n && arr[i + count] == duplicate) {
                count++;
            }

            printf("%d appears %d times\n", duplicate, count);
        }
    }

    return 0;
}


