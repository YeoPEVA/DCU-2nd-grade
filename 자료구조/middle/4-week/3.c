#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10
typedef char *element;

typedef struct {
    // 선형 큐 타입
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

int is_empty(QueueType *q);

// 오류 함수
void error(char *message){
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 선형 큐 초기화
void init_queue(QueueType *q){
    q->front = 0;
    q->rear = 0;
}

// 원형 큐 상태 출력 (수정해야함)
void queue_print(QueueType *q){
    printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
    if(!(is_empty(q))){
        int i = q->front;
        do {
            i = (i+1) % (MAX_QUEUE_SIZE);
            printf("%s | ", q->data[i]);
            if(i == q->rear) {
                break;
            }
        } while (i != q->front);
    }
    printf("\n");
}

// 원형 큐가 포화상태인가?
int is_full(QueueType *q){
    if((q->rear + 1) % MAX_QUEUE_SIZE == q->front){
        error("큐가 포화상태입니다.");
        return 1;
    }else{
        return 0;
    }
}


// 원형 큐가 공백상태인가?
int is_empty(QueueType *q){
    if(q->rear == q->front){
        error("큐가 공백상태입니다.");
        return 1;
    }else{
        return 0;
    }
}

// 원형 큐에 데이터 삽입
void enqueue(QueueType *q, char * item){
	if(is_full(q) == 1){
        return;
    }else{
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->data[q->rear] = item;
    }
}


// 원형 큐에서 데이터 제거
char * dequeue(QueueType *q){
	if(is_empty(q) == 1){
        return 0;
    }else{
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        return q->data[q->front];
    }
}

int main(void){
    int choice = 0;
    char personName[50];

    QueueType q;
	init_queue(&q);

    while(1){
        scanf("%d", &choice);

        switch (choice) {
            // 대기열 추가
            case 1:
                scanf("%s", personName);
                enqueue(&q, personName);
                break;
            // 탑승 처리
            case 2:
                dequeue(&q);
                break;
            // 대기열 출력
            case 3:
                queue_print(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("error");
        }
    }
}