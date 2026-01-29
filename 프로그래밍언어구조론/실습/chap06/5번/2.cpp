#include <iostream>
using namespace std;

int main(){
    printf("2024-11-26, 학번 : 20118669, 이창엽\n");
    int x;
    for(x=1; x<11; x++){
        if((x%5) == 0)
            continue;
        cout << x << " ";
    }
}