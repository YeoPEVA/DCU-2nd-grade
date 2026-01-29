#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main(){
    printf("2024-12-03, 학번 : 20117669, 이창엽\n");
    int x=10, y=20;
    swap(x,y);
    cout << x << ' ' << y;
}