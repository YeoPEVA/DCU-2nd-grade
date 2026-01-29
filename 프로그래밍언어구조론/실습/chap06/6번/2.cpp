#include <stdio.h>

int main() {
    printf("2024-11-26, 학번 : 20118669, 이창엽\n");
    int score;
    char grade;

    printf("점수를 입력하세요 (0-100): ");
    scanf("%d", &score);

    if(score > 100 || score < 0){
        printf("점수 범위를 벗어났습니다.\n");
        return 1;
    }

    switch (score / 10) {
        case 10:
        case 9:
            grade = 'A';
            break;
        case 8:
            grade = 'B';
            break;
        case 7:
            grade = 'C';
            break;
        case 6:
            grade = 'D';
            break;
        default:
            grade = 'F';
    }

    printf("학점: %c\n", grade);
    return 0;
}
