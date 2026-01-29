#include <iostream>
#include <string>

using namespace std;

int main(){ // 본인 이름으로 작성 
    printf("2024-11-05, 학번:20117669, 이름:이창엽\n");
    string f_name = "CHANG YEOB";
    string l_name = "LEE ";
    string name; 

    name = l_name + f_name;
    cout << name << endl;

    cout << name.length() << endl;
    name.append(" Fighting!");
    cout << name << endl;
    cout << name.at(10) << endl;
    cout << name.find("L") << endl;
    name.erase(0,4);

    cout << name << endl;
}