//
// Created by YeoPEVA on 3/7/24.
//

#include <stdio.h>

long long int input_check(int test){
    if(test >= 10000 && test <= 100000){
        return 1;
    }else{
        return 0;
    }
}

// - 알고리즘 A: sum = n(n+1)/2
long long int sum_way_a(long long int a){
    return (a*(a+1)/2);
}

// - 알고리즘 B: sum = 1 + 2 + ... + n
long long int sum_way_b(long long int a){
    if(a==1){
        return 1;
    }else{
        return a + sum_way_b(a-1);
    }
}

// - 알고리즘 C: sum = (1) + (1 + 1) + (1 + 1 + 1) + ..., (1 + 1 + ... + 1)

long long int sum_way_c(long long int a){
    if(a == 1) {
        return 1;
    }else{
        long long int sum = 0;
        for(int i =0; i<a; i++){
            sum +=1;
        }
        return sum + sum_way_c(a-1);
    }
}

int main() {
    long long int input_a = 0, input_b = 0, input_c = 0, check = 0;

    // 입력 3개
    scanf("%d", &input_a);
    scanf("%d", &input_b);
    scanf("%d", &input_c);

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

    printf("%ll %ll %ll %d\n", sum_way_a(input_a), sum_way_b(input_a), sum_way_c(input_a), input_a);

    printf("%ll %ll %ll %d\n", sum_way_a(input_b), sum_way_b(input_b), sum_way_c(input_b), input_b);

    printf("%ll %ll %ll %d\n", sum_way_a(input_c), sum_way_b(input_c), sum_way_c(input_c), input_c);

    return 0;
}
