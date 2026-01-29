#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    char names[MAX_QUEUE_SIZE][20];
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
    return q->count == 0;
}

void enqueue(QueueType *q, char *name) {
    if (isFull(q)) {
        printf("대기열이 가득 찼습니다.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    strcpy(q->names[q->rear], name);
    q->count++;
}

void dequeue(QueueType *q) {
    if (isEmpty(q)) {
        printf("대기열이 비어 있습니다.\n");
        return;
    }

    strcpy(q->names[q->rear + 1], q->names[q->front]);
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
}

void display(QueueType *q) {
    if (isEmpty(q)) {
        printf("대기열이 비어 있습니다.\n");
        return;
    }
    int i = q->front;
    for (int j = 0; j < q->count; j++) {
        printf("%s", q->names[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
        if(j < (q->count) -1 ){
            printf(", ");
        }
    }
    printf("\n");
}

int main() {
    QueueType queue;
    init_queue(&queue);

    int choice;
    char name[20];

    do {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%s", name);
                enqueue(&queue, name);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                return 0;
            default:
                printf("올바른 메뉴를 선택하세요.\n");
        }
    } while (choice != 4);

    return 0;
}
