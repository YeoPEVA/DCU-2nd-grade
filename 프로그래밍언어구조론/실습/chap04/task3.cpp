#include <iostream>
using namespace std;

int x; // 전역 변수

void sub1(void){
    cout << "x = " << x << endl;
}

void sub2(void){
    int x;
    x = 4;
    sub1();
}

int main(void){
    x = 2;
    sub2();

    return 0;
}