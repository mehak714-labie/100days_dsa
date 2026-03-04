//Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.
#include <stdio.h>

int main() {
    int rows, cols;
    int i,j;
    print("no of rows and columns:")
    scanf("%d %d", &rows, &cols);
    int matrix[rows][cols];
    for( i = 0; i < rows; i++) {
        for( j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while(top <= bottom && left <= right) {

        // 1. Top row (left ? right)
        for( i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++;

        // 2. Right column (top ? bottom)
        for( i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;

        // 3. Bottom row (right ? left)
        if(top <= bottom) {
            for( i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        // 4. Left column (bottom ? top)
        if(left <= right) {
            for( i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }

    return 0;
}
