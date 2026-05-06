#include <stdio.h>
#include <stdlib.h>

// Function to merge and count
void merge(int nums[], int indices[], int left, int mid, int right, int result[]) {
    int i = left, j = mid + 1;
    int rightCount = 0;
    int temp[right - left + 1];
    int tempIdx[right - left + 1];
    int k = 0;

    while (i <= mid && j <= right) {
        if (nums[indices[j]] < nums[indices[i]]) {
            temp[k] = nums[indices[j]];
            tempIdx[k++] = indices[j];
            rightCount++;
            j++;
        } else {
            result[indices[i]] += rightCount;
            temp[k] = nums[indices[i]];
            tempIdx[k++] = indices[i];
            i++;
        }
    }
    while (i <= mid) {
        result[indices[i]] += rightCount;
        temp[k] = nums[indices[i]];
        tempIdx[k++] = indices[i];
        i++;
    }
    while (j <= right) {
        temp[k] = nums[indices[j]];
        tempIdx[k++] = indices[j];
        j++;
    }
    for (int p = 0; p < k; p++) {
        indices[left + p] = tempIdx[p];
    }
}

void mergeSort(int nums[], int indices[], int left, int right, int result[]) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(nums, indices, left, mid, result);
    mergeSort(nums, indices, mid + 1, right, result);
    merge(nums, indices, left, mid, right, result);
}

int main() {
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    int result[n];
    int indices[n];

    for (int i = 0; i < n; i++) {
        result[i] = 0;
        indices[i] = i;
    }

    mergeSort(nums, indices, 0, n - 1, result);

    printf("Counts: [");
    for (int i = 0; i < n; i++) {
        printf("%d", result[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");

    return 0;
}