#include <stdio.h>

// Function to check if a year is a leap year
int isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int main() {
    int fromYear, toYear;
    int leapYears = 0, ordinaryYears = 0;

    // Input "from" and "to" years
    printf("Enter the 'from' year: ");
    scanf("%d", &fromYear);

    printf("Enter the 'to' year: ");
    scanf("%d", &toYear);

    // Validate the input
    if (fromYear > toYear) {
        printf("Invalid input. 'From' year should be less than or equal to 'to' year.\n");
        return 1; // Exit with an error code
    }

    // Loop through the years and count leap and ordinary years
    for (int year = fromYear; year <= toYear; ++year) {
        if (isLeapYear(year)) {
            leapYears++;
        } else {
            ordinaryYears++;
        }
    }

    // Display the results
    printf("Number of leap years between %d and %d: %d\n", fromYear, toYear, leapYears);
    printf("Number of ordinary years between %d and %d: %d\n", fromYear, toYear, ordinaryYears);

    return 0;
}

