//
// Created by hoseong on 2024-07-24.
//

#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

void HeapSort(int *arr, int n) {
    IntHeap heap;
    Initialize(&heap, n);
    for (int i = 0; i < n; i++) {
        Insert(&heap, arr[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        Remove(&heap, &arr[i]);
    }
    Terminate(&heap);
}

int main() {
    int i;
    int *x;
    int nx;
    printf("힙 정렬\n요소 개수 : ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    for (i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    HeapSort(x, nx);
    puts("completed");
    for (i = 0; i < nx; i++) {
        printf("x[%d] = %d\n", i, x[i]);
    }
    free(x);
    return 0;
}
