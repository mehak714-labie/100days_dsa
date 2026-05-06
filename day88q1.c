#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Check if we can place m cows with at least 'dist' apart
int canPlace(int position[], int n, int m, int dist) {
    int count = 1; // place first cow
    int lastPos = position[0];
    for (int i = 1; i < n; i++) {
        if (position[i] - lastPos >= dist) {
            count++;
            lastPos = position[i];
            if (count >= m) return 1; // success
        }
    }
    return 0; // not possible
}

int maxDistance(int position[], int n, int m) {
    qsort(position, n, sizeof(int), cmp);
    int low = 1;
    int high = position[n-1] - position[0];
    int ans = 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlace(position, n, m, mid)) {
            ans = mid;
            low = mid + 1; // try bigger distance
        } else {
            high = mid - 1; // reduce distance
        }
    }
    return ans;
}

int main() {
    int n, m;
    printf("Enter number of stalls and cows: ");
    scanf("%d %d", &n, &m);

    int position[n];
    printf("Enter stall positions: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &position[i]);
    }

    int result = maxDistance(position, n, m);
    printf("Maximum minimum distance = %d\n", result);

    return 0;
}