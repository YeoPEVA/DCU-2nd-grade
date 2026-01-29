#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100000

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    int items[MAX_NODES];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_NODES - 1)
        return; // overflow
    q->items[++q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q))
        return -1; // underflow
    return q->items[++q->front];
}

void addEdge(Node* adjList[], int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

void bfs(Node* adjList[], int parent[], int start) {
    Queue q;
    initQueue(&q);
    enqueue(&q, start);
    parent[start] = -1;

    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        Node* temp = adjList[current];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (parent[adjVertex] == 0) { // 아직 방문하지 않은 노드
                parent[adjVertex] = current;
                enqueue(&q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, u, v;
    scanf("%d", &n);
    
    Node* adjList[MAX_NODES] = {NULL};
    int parent[MAX_NODES] = {0};

    for (int i = 1; i < n; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adjList, u, v);
        addEdge(adjList, v, u);
    }

    bfs(adjList, parent, 1);

    for (int i = 2; i <= n; i++) {
        if (parent[i] != 0) {
            printf("%d > %d\n", i, parent[i]);
        }
    }

    return 0;
}
