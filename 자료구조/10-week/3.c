#include <stdio.h>
#include <stdlib.h>

int N;
int map[25][25];
int visited[25][25];
int houseCount[313];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int count;

void dfs(int x, int y, int index) {
    visited[x][y] = 1;
    houseCount[index]++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[nx][ny] == 1 && !visited[nx][ny]) {
            dfs(nx, ny, index);
        }
    }
}

void sort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    int complex = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                dfs(i, j, complex);
                complex++;
            }
        }
    }

    sort(houseCount, complex);
    printf("%d\n", complex);
    for (int i = 0; i < complex; i++) {
        printf("%d\n", houseCount[i]);
    }

    return 0;
}
