#include <stdio.h>
#include <stdlib.h>

// Comparator for sorting intervals by start time
int cmp(const void *a, const void *b) {
    int *intA = (int*)a;
    int *intB = (int*)b;
    return intA[0] - intB[0];
}

void mergeIntervals(int intervals[][2], int n) {
    // Sort intervals by start
    qsort(intervals, n, sizeof(intervals[0]), cmp);

    int merged[n][2];
    int count = 0;

    merged[0][0] = intervals[0][0];
    merged[0][1] = intervals[0][1];
    count = 1;

    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= merged[count - 1][1]) {
            // Overlap → merge
            if (intervals[i][1] > merged[count - 1][1]) {
                merged[count - 1][1] = intervals[i][1];
            }
        } else {
            // No overlap → new interval
            merged[count][0] = intervals[i][0];
            merged[count][1] = intervals[i][1];
            count++;
        }
    }

    // Print merged intervals
    printf("Merged intervals:\n");
    for (int i = 0; i < count; i++) {
        printf("[%d, %d]\n", merged[i][0], merged[i][1]);
    }
}

int main() {
    int intervals[][2] = {{1,3}, {2,6}, {8,10}, {15,18}};
    int n = sizeof(intervals) / sizeof(intervals[0]);

    mergeIntervals(intervals, n);

    return 0;
}