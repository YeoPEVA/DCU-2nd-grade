#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int index;
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

// 양방향 연결 리스트 초기화 함수
Node* createNode(int index, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->index = index;
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int main() {
    int N;
    scanf("%d", &N);

    Node *head = NULL, *tail = NULL, *current;
    for (int i = 0; i < N; i++) {
        int value;
        scanf("%d", &value);
        Node *newNode = createNode(i + 1, value);
        if (i == 0) {
            head = newNode;
            tail = newNode;
            current = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    head->prev = tail; // 원형 연결 리스트를 만듦
    tail->next = head;

    for (int i = 0; i < N; i++) {
        int steps = current->value;
        printf("%d", current->index);
        if (i < N - 1) {
            printf(" ");
        }

        current->prev->next = current->next; // 현재 노드 제거
        current->next->prev = current->prev;

        if (steps > 0) {
            for (int j = 0; j < steps; j++) {
                current = current->next; // 오른쪽으로 이동
            }
        } else {
            for (int j = 0; j < (-steps); j++) {
                current = current->prev; // 왼쪽으로 이동
            }
        }
    }
    printf("\n");
    return 0;
}



// 과녁 순서대로 출력하고 메모리 해제 함수
void printAndFreeList(Node *head) {
    Node *temp;
    while (head) {
        printf("%d ", head->index);
        temp = head;
        head = head->next;
        free(temp);
    }
}