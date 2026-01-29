#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000

typedef struct node {
    int vertex;
    struct node* next;
} Node;

int N, M, V;
Node* adjList[MAX_NODES];
int visited[MAX_NODES];

int queue[MAX_NODES];
int front = 0, rear = 0;

void enqueue(int v) {
    queue[rear++] = v;
}

int dequeue() {
    return queue[front++];
}

int queueIsEmpty() {
    return front == rear;
}

Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int src, int dest) {
    // 중복 간선 확인 및 추가하는 함수
    Node** node = &adjList[src];
    while (*node != NULL) {
        if ((*node)->vertex == dest) return;
        node = &((*node)->next);
    }
    *node = createNode(dest);

    node = &adjList[dest];
    while (*node != NULL) {
        if ((*node)->vertex == src) return;
        node = &((*node)->next);
    }
    *node = createNode(src);
}

void freeList(Node* head) {
    Node* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    Node* temp = adjList[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS(temp->vertex);
        }
        temp = temp->next;
    }
}

void BFS(int startVertex) {
    enqueue(startVertex);
    visited[startVertex] = 1;

    while (!queueIsEmpty()) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        for (Node* adjNode = adjList[currentVertex]; adjNode != NULL; adjNode = adjNode->next) {
            int adjVertex = adjNode->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(adjVertex);
            }
        }
    }
}

void sortAdjList() {
    for (int i = 1; i <= N; i++) {
        Node* head = adjList[i], *sorted = NULL;
        while (head) {
            Node* current = head;
            head = head->next;

            if (!sorted || sorted->vertex >= current->vertex) {
                current->next = sorted;
                sorted = current;
            } else {
                Node* temp = sorted;
                while (temp->next && temp->next->vertex < current->vertex) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
        }
        adjList[i] = sorted;
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &V);
    for (int i = 0; i < M; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    sortAdjList();

    memset(visited, 0, sizeof(visited));
    DFS(V);
    printf("\n");

    memset(visited, 0, sizeof(visited));
    BFS(V);
    printf("\n");

    for (int i = 1; i <= N; i++) {
        freeList(adjList[i]);
    }

    return 0;
}
