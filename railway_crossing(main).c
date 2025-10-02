#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    int choice;
    char place[50];
    char train1[50], train2[50];
    int delay1 = 0, delay2 = 0;
    int duration1 = 0, duration2 = 0;

    printf("=== Railway Gate Timing System ===\n");
    printf("1. Moula Ali Railway Gate\n");
    printf("2. Malkajgiri Railway Gate\n");
    printf("3. Bolarum Railway Gate\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            strcpy(place, "Moula Ali Railway Gate");
            strcpy(train1, "Express 101");
            delay1 = 12;
            duration1 = 4;
            strcpy(train2, "");
            delay2 = 0;
            duration2 = 0;
            break;
        case 2:
            strcpy(place, "Malkajgiri Railway Gate");
            strcpy(train1, "South Central Cargo");
            delay1 = 8;
            duration1 = 3;
            strcpy(train2, "Regional 303");
            delay2 = 10;
            duration2 = 5;
            break;
        case 3:
            strcpy(place, "Bolarum Railway Gate");
            strcpy(train1, "City Express");
            delay1 = 15;
            duration1 = 6;
            strcpy(train2, "");
            delay2 =0;
            duration2 =0;
            break;
        default:
            printf("Invalid choice! Please run the program again.\n");
            return 1;
    }

    time_t now;
    struct tm timeinfo;
    char timeStr[50];

    time(&now);
    timeinfo = *localtime(&now);

    strftime(timeStr, sizeof(timeStr), "%I:%M %p", &timeinfo);

    printf("\n--- Gate Info ---\n");
    printf("Place          : %s\n", place);
    printf("Current Time   : %s\n", timeStr);
    printf("Train 1        : %s (Delay: %d min, Duration: %d min)\n", train1, delay1, duration1);

    if (delay2 > 0) {
        printf("Train 2        : %s (Delay: %d min, Duration: %d min)\n", train2, delay2, duration2);
    }

    int endTime1 = delay1 + duration1;
    int endTime2 = delay2 + duration2;
    int gateOpenAfter;

    if (endTime1 > endTime2)
        gateOpenAfter = endTime1;
    else
        gateOpenAfter = endTime2;

    timeinfo.tm_min += gateOpenAfter;
    mktime(&timeinfo);  

    strftime(timeStr, sizeof(timeStr), "%I:%M %p", &timeinfo);
    printf("Gate Opens At  : %s\n", timeStr);

    printf("\nWait patiently and stay safe near the railway crossing!\n");

    return 0;
}

