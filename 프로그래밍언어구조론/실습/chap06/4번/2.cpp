#include <iostream>
using namespace std;

int main(){
    printf("2024-11-26, 학번 : 20118669, 이창엽\n");
    int n,sum = 0;

    for(n = 1; sum <= 10; n++){
        sum += n;
    }
    cout << "sum = " << sum << endl;
    cout << "n = "<< n << endl;
}