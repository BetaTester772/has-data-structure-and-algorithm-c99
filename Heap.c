//
// Created by hoseong on 2024-07-23.
//
#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"


int Initialize(IntHeap *h, int max) {
    h->num = 0;
    if ((h->heap = calloc(max, sizeof(int))) == NULL) {
        h->max = 0;
        return -1;
    }
    h->max = max;
    return 0;
}

int Insert(IntHeap *h, int x) {
    int i;
    i = h->num++;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (x <= h->heap[parent]) {
            break;
        }
        h->heap[i] = h->heap[parent];
        i = parent;
    }
    h->heap[i] = x;
    return 0;
}

int Remove(IntHeap *h, int *x) {
    if (h->num <= 0) {
        return -1;
    }
    *x = h->heap[0];
    int last = h->heap[--h->num];
    int parent = 0;
    int child = 1;
    while (child < h->num) {
        if (child + 1 < h->num && h->heap[child] < h->heap[child + 1]) {
            child++;
        }
        if (last >= h->heap[child]) {
            break;
        }
        h->heap[parent] = h->heap[child];
        parent = child;
        child = child * 2 + 1;
    }
    h->heap[parent] = last;
    return 0;
}

void Print(const IntHeap *h) {
    for (int i = 0; i < h->num; i++) {
        printf("%d ", h->heap[i]);
    }
    putchar('\n');
}

void Terminate(IntHeap *h) {
    if (h->heap != NULL) {
        free(h->heap);
    }
    h->max = h->num = 0;
}
