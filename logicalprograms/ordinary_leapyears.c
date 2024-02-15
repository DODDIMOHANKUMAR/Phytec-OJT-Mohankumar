#include <stdio.h>

int isLeapYear(int year) {
    // A year is a leap year if it is divisible by 4, but not divisible by 100 unless it is divisible by 400
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int main() {
    int startYear, endYear;
    int ordinaryYears = 0, leapYears = 0;

    // Input the range of years
    printf("Enter the start year: ");
    scanf("%d", &startYear);

    printf("Enter the end year: ");
    scanf("%d", &endYear);

    // Validate the input
    if (startYear > endYear) {
        printf("Invalid input: Start year cannot be greater than end year.\n");
        return 1;  // Exit with an error code
    }

    // Count the number of ordinary and leap years within the range
    for (int year = startYear; year <= endYear; year++) {
        if (isLeapYear(year)) {
            leapYears++;
        } else {
            ordinaryYears++;
        }
    }

    // Display the result
    printf("Number of ordinary years: %d\n", ordinaryYears);
    printf("Number of leap years: %d\n", leapYears);

    return 0;
}

