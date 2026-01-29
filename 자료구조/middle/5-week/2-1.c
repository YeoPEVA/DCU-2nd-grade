#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int *people = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        people[i] = i + 1;
    }

    int index = 0;

    for (int i = 0; i < N; i++) {
        index = (index + K - 1) % (N - i); // K번째 사람을 찾기 위한 인덱스 계산

        // 해당 인덱스의 사람 출력
        printf("%d", people[index]);

        // 배열에서 제거된 사람을 제외하고 배열 재구성
        for (int j = index; j < N - 1; j++) {
            people[j] = people[j + 1];
        }

        if (i < N - 1) {
            printf(", ");
        }
    }

    free(people);

    return 0;
}
