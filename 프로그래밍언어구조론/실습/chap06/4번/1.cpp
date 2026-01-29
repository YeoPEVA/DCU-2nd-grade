#include <iostream>
using namespace std;

int main(){
    printf("2024-11-26, 학번 : 20118669, 이창엽\n");
    int sum = 0, n = 1;
    while (sum <= 10){
        sum = sum + n;
        n = n + 1;
    }
    cout << "sum = " << sum << endl;
    cout << "n = " << n << endl;
}