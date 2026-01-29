#include <stdio.h>

void main(){
    float sum = 0.0;

    printf("2024-10-29, 학번:20117669, 이름:이창엽\n");
    int i;
    for(i=1; i<=10000;i ++)
        sum += 0.1;
    printf("실수 0.1을 만번 더한 결과 = %f\n", sum);
    printf("실수 0.1에 만을 곱한 결과 = %f\n", 0.1*10000);
}