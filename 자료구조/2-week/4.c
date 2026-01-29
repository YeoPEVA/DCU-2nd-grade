#include <stdio.h>

#define MAX_LEVEL 50
#define MAX_WIDTH 40
char screen[MAX_LEVEL][MAX_WIDTH];

// 문자열 초기화 screen
void initialize_screen() {
    for(int i = 0; i < MAX_LEVEL; i++){
        for(int j = 0; j < MAX_WIDTH; j++){
            screen[i][j] = '-';
        }
    }
}

// tree 작성
void draw_tree(int row, int left, int right) {
    if (row >= MAX_LEVEL) return;
    if (left > right) return;
    if (right - left < 2) return;

    int mid = (left + right) / 2;
    screen[row][mid] = 'X';

    draw_tree(row + 1, left, mid); // 왼쪽
    draw_tree(row + 1, mid, right); // 오른쪽
}

// 문자열 출력
void print_screen() {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < MAX_WIDTH; j++){
            printf("%c",screen[i][j]);
        }
        if(i >= 3){
            break;
        }else{
            printf("\n");
        }
    }
}

int main() {
    initialize_screen();
    draw_tree(0, 0, MAX_WIDTH);
    print_screen();

    return 0;
}
