#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5
typedef int element;

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
    q->front = -1;
    q->rear = - 1;

}

// 선형 큐 상태 출력 (check)
void queue_print(QueueType *q){
    // printf("Front Pos : %d, Rear Pos : %d\n", q->front, q->rear);
    for(int i = 0; i < 5; i++){
        if(i <= q->front || i > q->rear){
            printf(",");
        }else{
            int item = q->data[i];
            printf("%d,", item);
        }
    }
    printf("\n");
}

// 선형 큐가 포화상태인가?
int is_full(QueueType *q){
    if(q->rear == MAX_QUEUE_SIZE -1){
        error("큐가 포화상태입니다.");
        return 1;
    }else{
        return 0;
    }

	// 내용 추가..		return 1;
	// 내용 추가..		return 0;
}


// 선형 큐가 공백상태인가?
int is_empty(QueueType *q){
    if(q->rear == q->front){
        error("큐가 공백상태입니다.");
        return 1;
    }else{
        return 0;
    }

	// 내용 추가..		return 1;
	// 내용 추가..		return 0;
}

// 선형 큐에 데이터 삽입
void enqueue(QueueType *q, int item){
	if(is_full(q) == 1){
        return;
    }else{
        q->data[++(q->rear)] = item;
    }
}


// 선형 큐에서 데이터 제거
int dequeue(QueueType *q){
	if(is_empty(q) == 1){
        return 0;
    }else{
        int item = q->data[++(q->front)];
        q->data[q->front] = 0;

        return item;
    }
}

// 메인
int main(void){
	int item = 0;
	QueueType q;

	init_queue(&q);

	enqueue(&q, 10);
    queue_print(&q);
	enqueue(&q, 20);
    queue_print(&q);
	enqueue(&q, 30);
    queue_print(&q);

	item = dequeue(&q);
    queue_print(&q);
	item = dequeue(&q);
    queue_print(&q);
	item = dequeue(&q);
    queue_print(&q);

	return 0;
}