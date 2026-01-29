//
// Created by YeoPEVA on 6/6/24.
//

#include <stdio.h>

// 보간 탐색 함수
int interpolation_search(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (low == high) {
            if (arr[low] == key) return low;
            return -1;
        }
        // 보간 위치 계산
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]));

        if (arr[pos] == key) {
            return pos; // 키 값을 찾았을 때
        }

        if (arr[pos] < key) {
            low = pos + 1; // 탐색 범위를 오른쪽으로 조정
        } else {
            high = pos - 1; // 탐색 범위를 왼쪽으로 조정
        }
    }
    return -1; // 키 값이 배열에 없는 경우
}

int main() {
    // 정렬된 배열
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]); // 배열의 크기 계산

    int key;
    printf("Enter the value to search: ");
    scanf("%d", &key); // 사용자로부터 탐색할 값을 입력 받음

    int result = interpolation_search(arr, n, key);

    if (result != -1) {
        printf("Key found at index %d\n", result);
    } else {
        printf("Key not found\n");
    }

    return 0;
}
