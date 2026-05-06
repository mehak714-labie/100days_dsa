#include <stdio.h>
#include <stdlib.h>

// Merge function that counts inversions
long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;     // left subarray index
    int j = mid + 1;  // right subarray index
    int k = left;     // temp array index
    long long invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1); // all remaining left elements are greater
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left; i <= right; i++) arr[i] = temp[i];

    return invCount;
}

// Recursive merge sort that counts inversions
long long mergeSort(int arr[], int temp[], int left, int right) {
    long long invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        invCount += mergeSort(arr, temp, left, mid);
        invCount += mergeSort(arr, temp, mid + 1, right);

        invCount += merge(arr, temp, left, mid, right);
    }
    return invCount;
}

// Function to count inversions
long long countInversions(int arr[], int n) {
    int temp[n];
    return mergeSort(arr, temp, 0, n - 1);
}

int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    long long result = countInversions(arr, n);
    printf("Number of inversions: %lld\n", result);

    return 0;
}