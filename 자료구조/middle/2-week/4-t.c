#include <stdio.h>

#define MAX_LEVEL 50
#define MAX_WIDTH 40
char screen[MAX_LEVEL][MAX_WIDTH];

void initialize_screen() {
    for(int i = 0; i < MAX_LEVEL; i++){
        for(int j = 0; j < MAX_WIDTH; j++){
            screen[i][j] = '-';
        }
    }
}

void draw_tree(int row, int left, int right) {
    if (row >= MAX_LEVEL) return; // 범위 밖 체크
    if (left > right) return; // 잘못된 범위 체크
    if (right - left < 2) return; // 분할할 수 없는 경우

    int mid = (left + right) / 2; // 중간 지점 계산
    screen[row][mid] = 'X'; // 중간 지점에 'X' 표시

    // 현재 영역을 기준으로 왼쪽과 오른쪽 영역에 대해 재귀적으로 함수 호출
    draw_tree(row + 1, left, mid - 1); // 왼쪽 영역
    draw_tree(row + 1, mid + 1, right); // 오른쪽 영역
}

void print_screen() {
    for(int i = 0; i < MAX_LEVEL; i++){
        for(int j = 0; j < MAX_WIDTH; j++){
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initialize_screen();
    draw_tree(0, 0, MAX_WIDTH - 1); // 최초 호출시 전체 스크린을 대상으로 함
    print_screen();

    return 0;
}
