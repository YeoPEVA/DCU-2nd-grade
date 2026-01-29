#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5

// 학생 구조체 선언
struct Student {
    int studentNumber;
    float studentScore;
    char studentName[30];
};

// 학생 정보 입력 함수
void inputStudentData(struct Student *s) {
    int tmpA = 0;
    char tmpB[30];
    float tmpC = 0.0;

    scanf("%d", &tmpA);
    scanf("%s", tmpB);
    scanf("%f", &tmpC);

    s->studentNumber = tmpA;
    s->studentScore = tmpC;
    strcpy(s->studentName, tmpB);
}

// 학생 상세 정보 출력 함수
void displayStudentData(const struct Student *s) {
    printf("Student_Number: %d\n",s->studentNumber);
    printf("Name: %s\n",s->studentName);
    printf("Marks: %.2f\n", s->studentScore);
    printf("\n");
}

// 학생 점수 평균 계산 함수
// 계산 후 출력 진행
float calculateAverageMarks(const struct Student *students, int numStudents) {
    float average = 0.0;

    for (int i = 0; i<numStudents; i++){
        average += students[i].studentScore;
    }

    average = average / numStudents;
    printf("Average Marks of students: %.2f\n", average);

}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents;

    scanf("%d", &numStudents);

    // 학생 정보 입력
    for(int i = 0; i < numStudents; i++){
        inputStudentData(&students[i]);
    }
    // 학생 상세 정보 출력
    for (int i = 0; i < numStudents; i++){
        printf("Details for Student %d:\n", i + 1);
        displayStudentData(&students[i]);
    }
    // 학생들의 점수 평균 계산
    calculateAverageMarks(students, numStudents);

    return 0;
}
