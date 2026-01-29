#include <iostream>
using namespace std;

int x; // 전역 변수

void sub(void)
{
    double x; // sub() 지역 변수
    x = 3.14;
    ::x = 30;
    cout << "x = " << x << endl;
}

int main(void)
{
    x = 20;
    cout << "x = " << x << endl;
    sub();
    cout << "X = " << x << endl;
    return 0;
}