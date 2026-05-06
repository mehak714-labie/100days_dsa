#include <stdio.h>
#include <stdlib.h>

// Comparator for sorting intervals by start time
int cmpStart(const void *a, const void *b) {
    int *intA = (int*)a;
    int *intB = (int*)b;
    return intA[0] - intB[0];
}

// Function to find minimum number of meeting rooms
int minMeetingRooms(int intervals[][2], int n) {
    // Sort intervals by start time
    qsort(intervals, n, sizeof(intervals[0]), cmpStart);

    // Array to store end times of ongoing meetings
    int endTimes[n];
    int count = 0; // number of ongoing meetings
    int maxRooms = 0;

    for (int i = 0; i < n; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        // Free up rooms that have ended
        for (int j = 0; j < count; j++) {
            if (endTimes[j] <= start) {
                // Shift left to remove ended meeting
                for (int k = j; k < count - 1; k++) {
                    endTimes[k] = endTimes[k + 1];
                }
                count--;
                j--; // recheck current index
            }
        }

        // Add current meeting's end time
        endTimes[count++] = end;

        if (count > maxRooms) {
            maxRooms = count;
        }
    }

    return maxRooms;
}

int main() {
    int intervals[][2] = {{0,30}, {5,10}, {15,20}};
    int n = sizeof(intervals) / sizeof(intervals[0]);

    int result = minMeetingRooms(intervals, n);
    printf("Minimum number of meeting rooms required: %d\n", result);

    return 0;
}