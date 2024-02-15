#include <stdio.h>
#include <time.h>

void Timezones(struct tm* indianTime) {
    time_t indianTimestamp = mktime(indianTime);

    // London time zone (UTC+0)
    struct tm* londonTime = gmtime(&indianTimestamp);
    printf("London Time: %02d:%02d:%02d\n", londonTime->tm_hour, londonTime->tm_min, londonTime->tm_sec);

    // America/New_York time zone (UTC-5)
    struct tm* americaTime = localtime(&indianTimestamp);
    printf("America Time: %02d:%02d:%02d\n", americaTime->tm_hour, americaTime->tm_min, americaTime->tm_sec);
}

int main() {
    // Get Indian time
    time_t t = time(NULL);
    struct tm* indianTime = localtime(&t);

    printf("Enter Indian Time (HH:MM:SS): ");
    scanf("%d:%d:%d", &indianTime->tm_hour, &indianTime->tm_min, &indianTime->tm_sec);

    Timezones(indianTime);

    return 0;
}

