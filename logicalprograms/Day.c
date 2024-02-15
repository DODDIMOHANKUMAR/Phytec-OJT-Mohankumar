#include <stdio.h>

int dayOfWeek(int date, int month, int year) {
    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    year -= month < 3;
    int dayOfWeek = (year + year / 4 - year / 100 + year / 400 + t[month - 1] + date) % 7;

    // The result of dayOfWeek will be 0 for Saturday, 1 for Sunday, ..., 6 for Friday
    return dayOfWeek;
}

int main() {
    int date, month, year;

    // Input the date, month, and year
    printf("Enter the date month year: ");
    scanf("%d %d %d", &date,&month,&year);

   

    // Check for valid input
    if (date < 1 || date > 31 || month < 1 || month > 12) {
        printf("Invalid date or month.\n");
        return 1;  // Exit with an error code
    }

    // Calculate the day of the week
    int dayOfWeekValue = dayOfWeek(date, month, year);

    // Display the result
    switch (dayOfWeekValue) {
        case 0:
            printf("Sanday\n");
            break;
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("saturday\n");
            break;
	
    }

    return 0;
}

