#include<stdio.h>
#include<time.h>

void displayTimeInDifferentTimezones(struct tm *indianTime, const char *counterName) {
    time_t indianTimestamp = mktime(indianTime);

    // Time zones
    const char *timeZones[] = {
        "London (UTC+0)", "Austria (UTC+1)", "South Africa (UTC+2)",
        "China (UTC+8)", "Japan (UTC+9)", "Australia/Sydney (UTC+11)",
        "New Zealand (UTC+13)", "Alaska (UTC-9)", "Hawaii (UTC-10)",
        "Greenland (UTC-3)", "South Georgia (UTC-2)", "Canada (UTC-4)",
        // Add more time zones as needed...
    };

    int numCounters = sizeof(timeZones) / sizeof(timeZones[0]);

    int counterIndex = -1;
    for (int i = 0; i < numCounters; ++i) {
        if (strcmp(timeZones[i], counterName) == 0) {
            counterIndex = i;
            break;
        }
    }

    if (counterIndex == -1) {
      //  printf(".\n");
    } else {
        struct tm *tzTime;

        if (counterIndex == 0) {
            // London time zone (UTC+0)
            tzTime = gmtime(&indianTimestamp);
        } else {
            // Other time zones
            time_t tzTimestamp = indianTimestamp + (counterIndex - 5) * 3600;
            tzTime = localtime(&tzTimestamp);
        }

        printf("%s: %02d:%02d:%02d\n", timeZones[counterIndex], tzTime->tm_hour, tzTime->tm_min, tzTime->tm_sec);
    }
}

int main() {
    // Get Indian time
    time_t t = time(NULL);
    struct tm *indianTime = localtime(&t);

    char inputTime[9];
    char counterName[50];

    printf("Enter Indian Time (HH:MM:SS): ");
    scanf("%8s", inputTime);

    sscanf(inputTime, "%2d:%2d:%2d", &indianTime->tm_hour, &indianTime->tm_min, &indianTime->tm_sec);

    // Clear input buffer
    while (getchar() != '\n');

    printf("Enter the Counter Name: ");
    fgets(counterName, sizeof(counterName), stdin);
   // counterName[strcspn(counterName, "\n")] = '\0';  // Remove newline character

    displayTimeInDifferentTimezones(indianTime, counterName);

    return 0;
}

