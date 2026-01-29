#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front, rear, count;
} QueueType;

void init_queue(QueueType *queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
}

int isFull(QueueType *q) {
    return q->count == MAX_QUEUE_SIZE;
}

int isEmpty(QueueType *q) {
    return q->count <= 0;
}

int enqueue(QueueType *q, int data) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return 1;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = data;
    q->count++;
    return 0;
}

int dequeue(QueueType *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return 1;
    }

    q->data[q->rear + 1] = q->data[q->front];
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return 0;
}


int main() {
    int size;
    int data = 1;
    int result;

    scanf("%d", &size);

    QueueType queue;
    init_queue(&queue);

    while(1){
        result = enqueue(&queue,data);
        if(result){
            break;
        }
        printf("%d\n", data);
        data += 1;
    }

    while(1){
        result = dequeue(&dequeue);
        printf("%d\n", data);
        if(result){
            break;
        }
        data -= 1;
    }
    return 0;
}
