//
// Created by hoseong on 2024-07-23.
//

#ifndef DATASTRUCTUREANDALGORITHM_HEAP_H
#define DATASTRUCTUREANDALGORITHM_HEAP_H

#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

typedef struct {
    int max;
    int num;
    int *heap;
} IntHeap;

int Initialize(IntHeap *h, int max);

int Insert(IntHeap *h, int value);

int Remove(IntHeap *h, int *value);

void Print(const IntHeap *h);

void Terminate(IntHeap *h);

#endif //DATASTRUCTUREANDALGORITHM_HEAP_H
