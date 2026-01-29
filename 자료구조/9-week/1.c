#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 100

typedef struct {
    int key;
} Element;

typedef struct {
    Element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

void init(HeapType *h) {
    h->heap_size = 0;
}

void insert_max_heap(HeapType *h, int key) {
    int i;
    i = ++(h->heap_size);

    while ((i != 1) && (key > h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i].key = key;
}

int delete_max_heap(HeapType *h) {
    int parent, child;
    int item, temp;

    item = h->heap[1].key;
    temp = h->heap[(h->heap_size)--].key;
    parent = 1;
    child = 2;

    while (child <= h->heap_size) {
        if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key)) {
            child++;
        }
        if (temp >= h->heap[child].key) break;

        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent].key = temp;
    return item;
}

int main() {
    int key1, key2, key3;
    HeapType heap;

    init(&heap);

    scanf("%d %d %d", &key1, &key2, &key3);

    insert_max_heap(&heap, key1);
    insert_max_heap(&heap, key2);
    insert_max_heap(&heap, key3);

    printf("<%d>", delete_max_heap(&heap));
    printf("<%d>", delete_max_heap(&heap));
    printf("<%d>", delete_max_heap(&heap));

    return 0;
}
