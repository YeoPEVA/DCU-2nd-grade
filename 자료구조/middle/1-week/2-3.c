#include <stdio.h>

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
    long long int input_a = 0, input_b = 0, input_c = 0;

    // 입력 3개
    scanf("%lld %lld %lld", &input_a, &input_b, &input_c);

    if(input_a >= 10000 && input_a <= 100000 && input_b >= 10000 && input_b <= 100000 && input_c >= 10000 && input_c <= 100000) {
        printf("%lld %lld %lld %lld\n", sum_way_a(input_a), sum_way_b(input_a), sum_way_c(input_a), input_a);
        printf("%lld %lld %lld %lld\n", sum_way_a(input_b), sum_way_b(input_b), sum_way_c(input_b), input_b);
        printf("%lld %lld %lld %lld\n", sum_way_a(input_c), sum_way_b(input_c), sum_way_c(input_c), input_c);
    }else{
        return 0;
    }

    return 0;
}