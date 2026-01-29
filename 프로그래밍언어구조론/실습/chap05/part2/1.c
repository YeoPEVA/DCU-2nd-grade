#include <stdio.h>

int main(){
    printf("2024-11-05, 학번:20117669, 이름:이창엽\n");
    int i, a[5], b[5];

    printf("배열 a : ");

    for(i=0;i <5; i++){
        a[i] = (i+1) * 10;
        printf("%d ", a[i]);
    }

    // b = a; // 배열의 복사 

    printf("\n배열 b : ");
    for(i=0;i <5; i++){
        b[i] = a[i]; // 배열 원소 복사 
        printf("%d ", b[i]);
    }

    // int a[5] = {10,20,30,40,50};
    // for(i=0; i<5; i++)
    // printf("%d ",a[i]);

}