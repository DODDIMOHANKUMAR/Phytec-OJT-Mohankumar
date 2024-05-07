#include <stdio.h>
#include<stdlib.h>

int main() {
    char username[100]; // Declare an array to store the username
    unsigned long long int numericValue = 0; // Initialize a numeric value

    printf("Enter a username: ");
    scanf("%s", username); // Read the username as a string

    // Calculate the numeric value by summing the ASCII values of characters
    for (int i = 0; username[i] != '\0'; i++) {
        numericValue += (unsigned long long int)username[i];
    }

    printf("Username: %s\n", username);
    printf("Numeric Value: %llu\n", numericValue);

    return 0;
}

