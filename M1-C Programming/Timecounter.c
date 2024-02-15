#include <stdio.h>
#include <time.h>

void displayTimeInDifferentTimezones(struct tm *indianTime, int numCounters) {
    time_t indianTimestamp = mktime(indianTime);

    // Time zones
    const char *timeZones[] = {
        "London (UTC+0)", "Austria (UTC+1)", "South Africa (UTC+2)",
        "China (UTC+8)", "Japan (UTC+9)", "Australia/Sydney (UTC+11)",
        "New Zealand (UTC+13)", "Alaska (UTC-9)", "Hawaii (UTC-10)",
        "Greenland (UTC-3)","southGeorgia (UTC-2)","Canada (UTC-4)",

        
    };

    if (numCounters > sizeof(timeZones) / sizeof(timeZones[0])) 
    {
        numCounters = sizeof(timeZones) / sizeof(timeZones[0]);
        printf("Warning: Too many counters requested. Displaying up to %d counters.\n", numCounters);
    }

    for (int i = 0; i < numCounters; ++i) {
        struct tm *tzTime;

        if (i == 0) {
            // London time zone (UTC+0)
            tzTime = gmtime(&indianTimestamp);
        } else {
            // Other time zones
            time_t tzTimestamp = indianTimestamp + (i - 5) * 3600;
            tzTime = localtime(&tzTimestamp);
        }

        printf("%s: %02d:%02d:%02d\n", timeZones[i], tzTime->tm_hour, tzTime->tm_min, tzTime->tm_sec);
    }
}

int main() {
    // Get Indian time
    time_t t = time(NULL);
    struct tm *indianTime = localtime(&t);

    char inputTime[9];
    char countername;

    printf("Enter Indian Time (HH:MM:SS): ");
    scanf("%8s", inputTime);

    sscanf(inputTime, "%2d:%2d:%2d", &indianTime->tm_hour, &indianTime->tm_min, &indianTime->tm_sec);

    printf("Enter the CounterName: ");
    scanf("%c", &countername);

    displayTimeInDifferentTimezones(indianTime, countername);

    return 0;
}


