#include <iostream>
using namespace std;

template <class T>
T big(T a, T b){
    if(a>b)
        return a;
    else
        return b;
}

int main(){
    printf("2024-12-03, 학번 : 20117669, 이창엽\n");
    int a=20, b=50;
    char c = 'a', d='z';
    cout << "big(20,50)의 결과는 " << big(a,b) << endl;
    cout << "big('a', 'z')의 결과는 " << big(c,d) << endl;
}