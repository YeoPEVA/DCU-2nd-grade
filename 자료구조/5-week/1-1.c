#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *queue;
    int max_size;
    int front;
    int rear;
    int count;
} CircularQueue;

void initQueue(CircularQueue *cq, int max_size) {
    cq->queue = (int *)malloc(sizeof(int) * max_size);
    cq->max_size = max_size;
    cq->front = 0;
    cq->rear = 0;
    cq->count = 0;
}

int enqueue(CircularQueue *cq, int item) {
    if (cq->count < cq->max_size) {
        cq->queue[cq->rear] = item;
        cq->rear = (cq->rear + 1) % cq->max_size;
        cq->count++;
        return 1; // True
    } else {
        return 0; // False
    }
}

int dequeue(CircularQueue *cq) {
    if (cq->count > 0) {
        int item = cq->queue[cq->front];
        cq->front = (cq->front + 1) % cq->max_size;
        cq->count--;
        return item;
    } else {
        return -1; // empty
    }
}

void freeQueue(CircularQueue *cq) {
    free(cq->queue);
}

int main() {
    CircularQueue cq;
    int max_queue_size;

    scanf("%d", &max_queue_size);

    initQueue(&cq, max_queue_size);

    for (int i = 1; i <= max_queue_size + 1; i++) {
        if (enqueue(&cq, i)) {
            printf("%d\n", i);
        } else {
            printf("Queue is full. Cannot enqueue.\n");
            break;
        }
    }

    while (1) {
        int item = dequeue(&cq);
        if (item != -1) {
            printf("%d\n", item);
        } else {
            printf("Queue is empty. Cannot dequeue.\n");
            break;
        }
    }

    freeQueue(&cq);
    return 0;
}
