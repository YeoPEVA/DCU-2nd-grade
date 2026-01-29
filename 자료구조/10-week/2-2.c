#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1001

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
    if (front == rear) return -1;
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
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

void DFS(int v) {
    Node* temp = adjList[v];
    visited[v] = 1;
    printf("%d ", v);

    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS(temp->vertex);
        }
        temp = temp->next;
    }
}

void BFS(int startVertex) {
    Node* adjNode;

    enqueue(startVertex);
    visited[startVertex] = 1;

    while (!queueIsEmpty()) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        adjNode = adjList[currentVertex];
        while (adjNode != NULL) {
            int adjVertex = adjNode->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(adjVertex);
            }
            adjNode = adjNode->next;
        }
    }
}

void sortAdjList() {
    for (int i = 1; i <= N; i++) {
        Node *current = adjList[i], *index = NULL, *temp;
        int smallest;
        if (current != NULL) {
            while (current != NULL) {
                smallest = current->vertex;
                temp = current->next;
                index = current;
                while (temp != NULL) {
                    if (temp->vertex < smallest) {
                        smallest = temp->vertex;
                        index = temp;
                    }
                    temp = temp->next;
                }
                index->vertex = current->vertex;
                current->vertex = smallest;
                current = current->next;
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &V);
    int src, dest;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    sortAdjList();

    memset(visited, 0, sizeof(visited));
    DFS(V);
    printf("\n");

    memset(visited, 0, sizeof(visited));
    BFS(V);
    // printf("\n");

    return 0;
}
