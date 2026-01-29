//
// Created by YeoPEVA on 3/7/24.
//

#include <stdio.h>

double input_check(double test){
    if(test >= 10000 && test <= 100000){
        return 1;
    }else{
        return 0;
    }
}

// - 알고리즘 A: sum = n(n+1)/2
double sum_way_a(double a){
    return (a*(a+1)/2);
}

// - 알고리즘 B: sum = 1 + 2 + ... + n
double sum_way_b(double a) {
    double sum = 0;
    for(double i=1; i<=a; i++){
        sum += i;
    }
    return sum;
}

// - 알고리즘 C: sum = (1) + (1 + 1) + (1 + 1 + 1) + ..., (1 + 1 + ... + 1)
double sum_way_c(double a){
    double sum = 0;

    for(double i=1; i <= a; i++){
        double temp = 0;

        for(double j=1; j <= i; j++){
            temp += 1;
        }
        sum += temp;
    }

    return sum;
}

int main() {
    double input_a = 0, input_b = 0, input_c = 0, check = 0;

    // 입력 3개
    scanf("%lf", &input_a);
    scanf("%lf", &input_b);
    scanf("%lf", &input_c);

    check = input_check(input_a);
    if(check != 1){
        return 0;
    }
    check = input_check(input_b);
    if(check != 1){
        return 0;
    }
    check = input_check(input_c);
    if(check != 1){
        return 0;
    }

    printf("%.0lf %.0lf %.0lf %.0lf\n", sum_way_a(input_a), sum_way_b(input_a), sum_way_c(input_a), input_a);
    printf("%.0lf %.0lf %.0lf %.0lf\n", sum_way_a(input_b), sum_way_b(input_b), sum_way_c(input_b), input_b);
    printf("%.0lf %.0lf %.0lf %.0lf\n", sum_way_a(input_c), sum_way_b(input_c), sum_way_c(input_c), input_c);

    return 0;
}


// - 알고리즘 C: sum = (1) + (1 + 1) + (1 + 1 + 1) + ..., (1 + 1 + ... + 1)
/*
double sum_way_c(double a){
    if(a == 1) {
        return 1;
    }else{
        double sum = 0;
        for(int i =0; i<a; i++){
            sum +=1;
        }
        return sum + sum_way_c(a-1);
    }
}

double sum_way_b(double a){
    if(a==1){
        return 1;
    }else{
        return a + sum_way_b(a-1);
    }
 */