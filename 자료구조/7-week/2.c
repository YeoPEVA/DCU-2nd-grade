#include <stdio.h>
#include <stdlib.h>

int count = 0;
int *cols;

int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (cols[i] == col ||
            abs(cols[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void placeQueen(int row, int n) {
    if (row == n) {
        count++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            cols[row] = col;
            placeQueen(row + 1, n);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    cols = (int *)malloc(n * sizeof(int));

    placeQueen(0, n);
    printf("%d\n", count);

    free(cols);
    return 0;
}
