#include <stdio.h>

// 구조체 테스트

typedef struct studentTag{
    char name[10];
    int age;
    double gpa;
}student;

int main(int argc, char * argv[]){
    student a = {"kim", 20, 4.3};
    student b = {"park", 21, 4.2};
    return 0;
}