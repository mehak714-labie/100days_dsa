//Problem: Given an array of integers, rotate the array to the right by k positions.
#include <stdio.h>
int main() {
    int n, k, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n], temp[n];
    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);    }
    printf("Enter value of k: ");
    scanf("%d", &k);
    k = k % n;  // Handle k > n
    for(i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];    }
    // Copy remaining elements
    for(i = 0; i < n - k; i++) {
        temp[k + i] = arr[i];
    }
    printf("Array after right rotation:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }
    return 0;
}
