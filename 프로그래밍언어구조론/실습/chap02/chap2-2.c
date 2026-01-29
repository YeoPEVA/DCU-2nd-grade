#include <stdio.h>
// 재귀 호출 기법 사용 

// 함수 선언 
int sum(int n){
    if (n <= 0)
        return 0;
    else
        return n + sum(n-1); // 재귀 호출  
}

int main(){
    // 변수 선언문 
    int n, result = 0;

    // 출력문 - 정보 출력 
    printf("2024-9-24, 학번:20117669, 이름:이창엽\n");

    // 출력문 - 정수 입력 안내 
    printf("정수를 입력하세요 : ");
    // 입력문 - 사용자 입력 
    scanf("%d", &n);

    // 함수 호출문 
    result = sum(n);

    // 출력문 - 결과 출력 
    printf("1부터 %d 까지의 합 : %d\n", n, result);
}