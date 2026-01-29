#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_K 50
#define MAX_DIGITS 101

char* numbers[MAX_K];  // 숫자를 저장할 포인터 배열

// 문자열 비교 함수
int compare(const void *a, const void *b) {
    const char *x = *(const char**)a;
    const char *y = *(const char**)b;
    char leftRight[MAX_DIGITS * 2];
    char rightLeft[MAX_DIGITS * 2];

    // x와 y를 서로 다른 순서로 결합
    strcpy(leftRight, x);
    strcat(leftRight, y);
    strcpy(rightLeft, y);
    strcat(rightLeft, x);

    // 내림차순 정렬을 위해 두 문자열 비교
    return strcmp(rightLeft, leftRight);
}

int main() {
    int K, N;
    scanf("%d %d", &K, &N);

    for (int i = 0; i < K; i++) {
        numbers[i] = (char*) malloc(sizeof(char) * MAX_DIGITS);
        scanf("%s", numbers[i]);
    }

    // 숫자를 비교할 수 있는 조건으로 정렬
    qsort(numbers, K, sizeof(char*), compare);

    // 최대 조합을 위해 최적의 숫자를 N-K번 출력
    for (int i = 0; i < N - K; i++) {
        printf("%s", numbers[0]);
    }

    // 모든 숫자들을 최소 한 번씩 출력
    for (int i = 0; i < K; i++) {
        printf("%s", numbers[i]);
    }

    printf("\n");

    // 동적 할당된 메모리 해제
    for (int i = 0; i < K; i++) {
        free(numbers[i]);
    }

    return 0;
}
