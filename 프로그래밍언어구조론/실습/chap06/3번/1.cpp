#include <iostream>
using namespace std;

int main(){
    int num, abs;
    printf("2024-11-26, 학번 : 20118669, 이창엽\n");
    cout << "임의의 정수를 입력하세요 : ";
    cin >> num;

    // abs = (num >0) ? num : -num;
    if(num > 0){
        abs = num;
    }else{
        abs = -num;
    }

    cout << num << "의 절대값 = " << abs << endl;
}