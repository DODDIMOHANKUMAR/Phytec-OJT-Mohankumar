#include <stdio.h>

int main() {
    char buffer[50];
    int num;
    float pi;

    // Format and write data to the string buffer
    scanf("Enter the Number%d and %f",num,pi);
    sprintf(buffer, "The number is %d and the value of pi is %.2f", num, pi);

    // Print the formatted string
    printf("%s\n", buffer);

    return 0;
}

