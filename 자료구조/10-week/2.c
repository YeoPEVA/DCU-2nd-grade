#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 1001

typedef struct {
    int vertex;
    struct Node* next;
} Node;

int N, M, V;
Node* graph[MAX_VERTICES];
int visited[MAX_VERTICES];

void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = graph[u];
    graph[u] = newNode;
}

void sortList(Node** head) {
    if (*head == NULL || (*head)->next == NULL) return;

    Node *i, *j;
    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->vertex > j->vertex) {
                int temp = i->vertex;
                i->vertex = j->vertex;
                j->vertex = temp;
            }
        }
    }
}

void dfs(int v) {
    Node* temp = graph[v];
    visited[v] = 1;
    printf("%d ", v);

    while (temp != NULL) {
        if (!visited[temp->vertex])
            dfs(temp->vertex);
        temp = temp->next;
    }
}

void bfs(int start) {
    int queue[MAX_VERTICES], front = 0, rear = 0, v;
    Node* temp;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        v = queue[front++];
        printf("%d ", v);
        temp = graph[v];

        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int u, v;
    scanf("%d %d %d", &N, &M, &V);

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    for (int i = 1; i <= N; i++) {
        sortList(&graph[i]);
    }

    memset(visited, 0, sizeof(visited));
    dfs(V);
    printf("\n");

    memset(visited, 0, sizeof(visited));
    bfs(V);
    printf("\n");

    return 0;
}
