//
// Created by YeoPEVA on 6/6/24.
//

#include <stdio.h>

// 이진 탐색 함수
int binary_search(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid; // 키 값의 위치 반환
        } else if (arr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1; // 키 값을 찾지 못하면 -1 반환
}

int main() {
    // 정렬된 배열
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]); // 배열의 길이 계산

    int key;
    printf("Enter the value to search: ");
    scanf("%d", &key); // 사용자로부터 탐색할 값을 입력 받음

    int result = binary_search(arr, n, key);

    if (result != -1) {
        printf("Key found at index %d\n", result);
    } else {
        printf("Key not old found\n");
    }

    return 0;
}
