#include <stdio.h>

int input_check(int test){
    if(test >= 10000 && test <= 100000){
        return 1;
    }else{
        return 0;
    }
}

// - 알고리즘 A: sum = n(n+1)/2
long long int sum_way_a(int a){
    return (long long int) a*(a+1)/2;
}

// - 알고리즘 B: sum = 1 + 2 + ... + n
long long int sum_way_b(int a) {
    long long int sum = 0;
    for(int i=1; i<=a; i++){
        sum += i;
    }
    return (long long int) sum;
}

// - 알고리즘 C: sum = (1) + (1 + 1) + (1 + 1 + 1) + ..., (1 + 1 + ... + 1)
long long int sum_way_c(int a){
    long long int sum = 0;

    for(int i=1; i <= a; i++){
        long long int temp = 0;

        for(int j=1; j <= i; j++){
            temp += 1;
        }
        sum += temp;
    }

    return (long long int) sum;
}

int main() {
    int input_a = 0, input_b = 0, input_c = 0;
    int check = 0;

    // 입력 3개
    scanf("%d %d %d", &input_a, &input_b, &input_c);
    // scanf("%d", &input_b);
    // scanf("%d", &input_c);

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

    printf("%lld %lld %lld %d\n", sum_way_a(input_a), sum_way_b(input_a), sum_way_c(input_a), input_a);
    printf("%lld %lld %lld %d\n", sum_way_a(input_b), sum_way_b(input_b), sum_way_c(input_b), input_b);
    printf("%lld %lld %lld %d\n", sum_way_a(input_c), sum_way_b(input_c), sum_way_c(input_c), input_c);

    return 0;
}