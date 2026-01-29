#include <stdio.h>

int big = 48;

void add(int &a, int &b) // 형식매개변수 (참조변수 타입)
{
    big += 10;
    a += 2;
    b += 4;
}

int main()
{
    printf("2024-12-03, 학번 : 20118669, 이창엽\n");
    int i = 2;
    add(i, big); // 실매개변수(참조)
    printf("i = %d, big = %d\n", i, big);
}