#include <stdio.h>
#include <limits.h>

#define V 7

int graph[V][V] = {
    {0, 7, 0, 0, 3, 10, 0},
    {7, 0, 4, 0, 2, 0, 0},
    {0, 4, 0, 2, 0, 9, 0},
    {0, 0, 2, 0, 0, 0, 4},
    {3, 2, 0, 0, 0, 0, 11},
    {10, 0, 9, 0, 0, 0, 0},
    {0, 0, 0, 4, 11, 0, 0}
};

int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printStep(int dist[], int sptSet[], int step) {
    printf("STEP %d\n", step);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            printf("* ");
        else
            printf("%d ", dist[i]);
    }
    printf("\n");
    for (int i = 0; i < V; i++) {
        printf("%d ", sptSet[i]);
    }
    printf("\n\n");
}

void dijkstra(int graph[V][V], int src) {
    int dist[V], sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[src] = 0;

    // 첫 번째 출력
    printStep(dist, sptSet, 1);

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }

        printStep(dist, sptSet, count + 2);
    }
}

int main() {
    dijkstra(graph, 0);
    return 0;
}
