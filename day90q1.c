#include <stdio.h>

// Function to check if boards can be painted with given max time
int isPossible(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currSum = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime) return 0; // single board exceeds maxTime
        if (currSum + boards[i] > maxTime) {
            painters++;
            currSum = boards[i];
            if (painters > k) return 0;
        } else {
            currSum += boards[i];
        }
    }
    return 1;
}

// Function to find minimum time
int minTime(int boards[], int n, int k) {
    int low = boards[0], high = 0;
    for (int i = 0; i < n; i++) {
        if (boards[i] > low) low = boards[i];
        high += boards[i];
    }

    int ans = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int boards[] = {10, 20, 30, 40};
    int n = sizeof(boards) / sizeof(boards[0]);
    int k = 2;

    int result = minTime(boards, n, k);
    printf("Minimum time required: %d\n", result);

    return 0;
}