#include <stdio.h>
#include <stdlib.h>

// Comparator for sorting cars by position (descending)
int cmp(const void *a, const void *b) {
    int posA = ((int*)a)[0];
    int posB = ((int*)b)[0];
    return posB - posA; // descending order
}

int carFleet(int target, int position[], int speed[], int n) {
    // Each car: position + time to reach target
    double cars[n][2];
    for (int i = 0; i < n; i++) {
        cars[i][0] = position[i];
        cars[i][1] = (double)(target - position[i]) / speed[i];
    }

    // Sort by position descending
    qsort(cars, n, sizeof(cars[0]), cmp);

    int fleets = 0;
    double currMaxTime = 0.0;

    for (int i = 0; i < n; i++) {
        if (cars[i][1] > currMaxTime) {
            fleets++;
            currMaxTime = cars[i][1];
        }
    }
    return fleets;
}

int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int n = sizeof(position) / sizeof(position[0]);

    int result = carFleet(target, position, speed, n);
    printf("Number of car fleets: %d\n", result);

    return 0;
}