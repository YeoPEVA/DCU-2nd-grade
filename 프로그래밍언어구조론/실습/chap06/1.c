#include <stdio.h>

int x = 10;

int func(void)
{
    x = 20;
    return 30;
}

int main(void)
{
    printf("2024-11-19, 학번 : 20118669, 이창엽\n");
    // printf("%d\n", x + func());
    printf("%d\n", func() + x);
    return 0;
}