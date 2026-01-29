#include <stdio.h>

#define BIT 16 // 매크로 상수 

int main(){
    int n;

    printf("2024-10-29, 학번:20117669, 이름:이창엽\n");
    printf("임의의 수를 입력하세요. : ");
    scanf("%d", &n);

    printf("정수 %2d의 %d 비트 표현 >> \n", n, BIT);

    for (int i = BIT - 1; i>= 0; i--){
        printf("%2d", n >> i & 1);
    }
    printf("\n");

}