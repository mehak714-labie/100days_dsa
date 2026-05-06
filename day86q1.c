#include <stdio.h>

int integerSqrt(int n) {
    if (n == 0 || n == 1) return n;

    int left = 1, right = n, ans = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (mid <= n / mid) {   // avoid overflow: mid*mid <= n
            ans = mid;          // store possible answer
            left = mid + 1;     // move right
        } else {
            right = mid - 1;    // move left
        }
    }
    return ans;
}

int main() {
    int n;
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    int result = integerSqrt(n);
    printf("Integer square root of %d is %d\n", n, result);

    return 0;
}