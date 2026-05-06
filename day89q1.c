#include <stdio.h>

int isPossible(int books[], int n, int m, int maxPages) {
    int students = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (books[i] > maxPages) {
            return 0; // single book exceeds maxPages
        }
        if (sum + books[i] > maxPages) {
            students++;
            sum = books[i];
            if (students > m) return 0;
        } else {
            sum += books[i];
        }
    }
    return 1;
}

int allocateBooks(int books[], int n, int m) {
    if (m > n) return -1; // not enough books

    int low = books[0], high = 0;
    for (int i = 0; i < n; i++) {
        if (books[i] > low) low = books[i]; // max single book
        high += books[i]; // sum of all pages
    }

    int result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(books, n, m, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    int n, m;
    printf("Enter number of books and students: ");
    scanf("%d %d", &n, &m);

    int books[n];
    printf("Enter pages in each book: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
    }

    int ans = allocateBooks(books, n, m);
    printf("Minimum possible maximum pages = %d\n", ans);

    return 0;
}