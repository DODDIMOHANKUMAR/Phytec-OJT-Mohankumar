#include <stdio.h>

enum Days {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

int main() {
    enum Days today = SUNDAY;
    
    printf("Today is ");
    
    switch (today) {
        case SUNDAY: printf("Sunday"); break;
        case MONDAY: printf("Monday"); break;
        case TUESDAY: printf("Tuesday"); break;
        case WEDNESDAY: printf("Wednesday"); break;
        case THURSDAY: printf("Thursday"); break;
        case FRIDAY: printf("Friday"); break;
        case SATURDAY: printf("Saturday"); break;
        default: printf("Invalid day");
    }
    
    printf("\n");
    
    return 0;
}

