#include <stdio.h>
#include <stdlib.h>

// Insertion sort for each bucket
void insertionSort(double arr[], int n) {
    for (int i = 1; i < n; i++) {
        double key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Bucket Sort function
void bucketSort(double arr[], int n) {
    // Create n empty buckets
    double *buckets[n];
    int bucketSizes[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = (double*)malloc(n * sizeof(double));
        bucketSizes[i] = 0;
    }

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bi = (int)(n * arr[i]); // bucket index
        buckets[bi][bucketSizes[bi]++] = arr[i];
    }

    // Sort each bucket
    for (int i = 0; i < n; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
        }
    }

    // Concatenate buckets
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[idx++] = buckets[i][j];
        }
        free(buckets[i]);
    }
}

int main() {
    double arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}