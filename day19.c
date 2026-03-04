//Problem: Write a program to find the maximum and minimum values present in a given array of integers.
#include <stdio.h>
int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);    }
    int max = arr[0];
    int min = arr[0];
    for(i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];        }
        if(arr[i] < min) {
            min = arr[i];        }    }
    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);
    return 0;   }
