#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 

// 노드 구조 정의 
typedef struct list{
    int data;
    struct list* next;
}list;


int main(){
    printf("2024-11-19, 학번 : 20117669, 이창엽\n");
    // 구조체 타입의 포인터 변수 선언
    list * p1;
	
    // 메모리 동적 할당
    p1 = (list *)malloc(sizeof(list));

    /// 생성된 노드에 데이터 입력
    p1->data = 10; 
    p1->next = NULL;

    // 새로운 노드 생성 및 값 입력 (20,30)
    p1->next = (list*)malloc(sizeof(list));
    p1->next->data = 20;
    p1->next->next = (list *)malloc(sizeof(list));

    p1->next->next->data = 30;
    p1->next->next->next = NULL;

    printf("p1=%p, p1->data=%3d, p1->next=%p\n", p1, p1->data, p1->next);
    
    list *ptr = p1; // 새롭게 추가한 문장 -> 쓰레기 발생 방지 

    printf("\n== 연결 리스트의 원소 ==\n");
    while(ptr != NULL){
        printf("%5d", ptr->data); // 마지막 노드 데이터 출력 
        ptr = ptr->next;
    }
    // 노드 반환 
    free(p1);
}