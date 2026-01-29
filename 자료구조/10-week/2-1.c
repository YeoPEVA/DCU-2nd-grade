#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 1001

int N, M, V;
int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

int stack[MAX_VERTICES];
int top = -1;

int queue[MAX_VERTICES];
int front = 0, rear = 0;

void push(int vertex) {
    stack[++top] = vertex;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

void enqueue(int vertex) {
    queue[rear++] = vertex;
}

int dequeue() {
    if (front == rear) return -1;
    return queue[front++];
}

void dfs(int start) {
    for (int i = 0; i <= N; i++) {
        visited[i] = 0;
    }
    push(start);
    visited[start] = 1;
    printf("%d ", start);

    while (top != -1) {
        int current = pop();
        for (int i = 1; i <= N; i++) {
            if (graph[current][i] && !visited[i]) {
                push(current);
                push(i);
                visited[i] = 1;
                printf("%d ", i);
                break;
            }
        }
    }
    printf("\n");
}

void bfs(int start) {
    for (int i = 0; i <= N; i++) {
        visited[i] = 0;
    }
    enqueue(start);
    visited[start] = 1;

    while (front != rear) {
        int current = dequeue();
        printf("%d ", current);
        for (int i = 1; i <= N; i++) {
            if (graph[current][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    // printf("\n");
}

int main() {
    scanf("%d %d %d", &N, &M, &V);
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    dfs(V);
    bfs(V);

    return 0;
}
