#include <stdio.h>


void matrix_diff(int * inputA, int * inputB, int * result){
    for(int i = 0; i<10; i++){
        result[i] = inputA[i] - inputB[i];
    }
}

int main(int argc, char *argv[]){

    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int b[10] = {10,9,8,7,6,5,4,3,2,1};
    int c[10];

    matrix_diff(a,b,c);

    for(int i=0; i<10; i++){
        printf("%d ", c[i]);
    }

    return 0;
}