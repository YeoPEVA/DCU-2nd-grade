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

    if (score >= 90 && score <= 100)
        grade = 'A';
    else if (score >= 80)
        grade = 'B';
    else if (score >= 70)
        grade = 'C';
    else if (score >= 60)
        grade = 'D';
    else
        grade = 'F';

    printf("학점: %c\n", grade);
    return 0;
}
