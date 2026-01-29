#include <stdio.h>

void main(){
    printf("2024-11-19, 학번:20117669, 이창엽\n");

    int a = 10, b = 5, c = 3;
    // a, b 값 다양하게 변경시켜 실행시켜보기
    if(a++ < 10 && b++ > 5)
        c++;
    else 
        c--;
    
    printf("a = %d, b = %d, c = %d\n", a,b,c);
}