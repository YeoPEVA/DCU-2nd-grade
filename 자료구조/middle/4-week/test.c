#include <stdio.h>


typedef char element;

typedef struct
{
    int front;
    int rear;
    element data[SIZE];
} QueueType;

// 초기 설정
void init(QueueType *Q)
{
    Q->rear = -1;
    Q->front = -1;
}

// 비어 있는지 체크
int is_empty(QueueType *Q)
{
    if(Q->front == Q->rear)
        return 1;
    else
        return 0;
}

// 큐가 가득찼는지 확인
int is_full(QueueType *Q)
{
    if(Q->rear == SIZE - 1)
        return 1;
    else
        return 0;

}

// 후미 요소 요소 추가
void enqueue(QueueType *Q, element e)
{
    if(is_full(Q)){
        return;
    }
    Q->data[++(Q->rear)] = e;
}

// 전면 요소 제거 및 반환
element dequeue(QueueType *Q)
{
    if(is_empty(Q)){
        return 1;
    }
    char item = Q->data[++(Q->front)];
    return item;
}

// 큐 출력
void print(QueueType *Q)
{
    int count = 0;

    if(is_empty(Q)){
        return;
    }

    printf("Front Pos : %d, Rear Pos : %d\n", Q->front, Q->rear);

    while(1){
        char item = Q->data[Q->front + count + 1];
        printf("[%c] ", item);
        if(Q->rear == count){
            break;
        }
        count += 1;
    }
    printf("\n");
}

int main(void){
    printf("test");
    return 0;
}