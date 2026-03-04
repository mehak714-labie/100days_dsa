//Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.
#include <stdio.h>
int main() {
    int n, i, j;
    int count = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);    }
    // Check all subarrays
    for(i = 0; i < n; i++) {
        int sum = 0;
        for(j = i; j < n; j++) {
            sum += arr[j];
            if(sum == 0) {
                count++;            }        }    }
    printf("Number of subarrays with sum 0 = %d", count);
    return 0;
}
