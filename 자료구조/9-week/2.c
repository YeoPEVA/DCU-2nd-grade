#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int capacity;
    int size;
} Heap;

void initHeap(Heap *h, int capacity) {
    h->data = (int *)malloc(capacity * sizeof(int));
    h->capacity = capacity;
    h->size = 0;
}

void resizeHeap(Heap *h) {
    h->capacity *= 2;
    h->data = (int *)realloc(h->data, h->capacity * sizeof(int));
}

void insertMaxHeap(Heap *h, int value) {
    if (h->size == h->capacity) {
        resizeHeap(h);
    }
    int i = h->size++;
    while (i != 0 && value > h->data[(i - 1) / 2]) {
        h->data[i] = h->data[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    h->data[i] = value;
}

int deleteMaxHeap(Heap *h) {
    int parent, child;
    int max, last;
    if (h->size == 0) return -1;
    max = h->data[0];
    last = h->data[--h->size];
    parent = 0;
    child = 1;
    while (child < h->size) {
        if (child + 1 < h->size && h->data[child] < h->data[child + 1]) {
            child++;
        }
        if (last >= h->data[child]) break;
        h->data[parent] = h->data[child];
        parent = child;
        child = 2 * child + 1;
    }
    h->data[parent] = last;
    return max;
}

void heapSort(int *array, int n) {
    Heap heap;
    initHeap(&heap, n);
    for (int i = 0; i < n; i++) {
        insertMaxHeap(&heap, array[i]);
    }
    for (int i = 0; i < n; i++) {
        array[i] = deleteMaxHeap(&heap);
    }
    free(heap.data);
}

int main() {
    int array[] = {56, 34, 23, 99, 56, 27, 11, 9};
    int n = sizeof(array) / sizeof(array[0]);

    heapSort(array, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
