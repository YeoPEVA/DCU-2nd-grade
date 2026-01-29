#include <stdio.h>

int main(){
    int sam[4][5], a =0;
    printf("2024-11-05, 학번:20117669, 이름:이창엽\n");

    for(int i=0; i<4;i++){
        for(int j=0; j<5;j++){
            sam[i][j] = ++a; 
            printf("%2d ", sam[i][j]);
        }
        printf("\n");
    }

    printf("&sam[0][0]=%u\n", &sam[0][0]);
    printf("&sam[2][1]=%u\n", &sam[2][1]);

    
    return 0;
}