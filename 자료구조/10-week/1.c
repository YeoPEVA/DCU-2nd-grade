#include <stdio.h>
#include <stdlib.h>

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int N, M;
int maze[100][100];
int visited[100][100];

typedef struct {
    int x, y, dist;
} Queue;

Queue queue[10000];
int front = 0, rear = 0;

void push(int x, int y, int dist) {
    queue[rear].x = x;
    queue[rear].y = y;
    queue[rear].dist = dist;
    rear++;
}

Queue pop() {
    return queue[front++];
}

int bfs(int startX, int startY) {
    push(startX, startY, 1);
    visited[startX][startY] = 1;

    while (front < rear) {
        Queue current = pop();
        if (current.x == N - 1 && current.y == M - 1) {
            return current.dist;
        }

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && maze[nx][ny] == 1) {
                visited[nx][ny] = 1;
                push(nx, ny, current.dist + 1);
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }

    int answer = bfs(0, 0);
    printf("%d\n", answer);

    return 0;
}
