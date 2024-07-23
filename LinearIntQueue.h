//
// Created by hoseong on 2024-07-23.
//

#ifndef DATASTRUCTUREANDALGORITHM_LINEARINTQUEUE_H
#define DATASTRUCTUREANDALGORITHM_LINEARINTQUEUE_H

typedef struct {
    int max;
    int num;
    int *que;
} LinearIntQueue;

int Initialize(LinearIntQueue *q, int max);

int Enque(LinearIntQueue *q, int x);

int Deque(LinearIntQueue *q, int *x);

int Peek(const LinearIntQueue *q, int *x);

void Clear(LinearIntQueue *q);

int Capacity(const LinearIntQueue *q);

int Size(const LinearIntQueue *q);

int IsEmpty(const LinearIntQueue *q);

int IsFull(const LinearIntQueue *q);

int Search(const LinearIntQueue *q, int x);

void Print(const LinearIntQueue *q);

void Terminate(LinearIntQueue *q);

#endif //DATASTRUCTUREANDALGORITHM_LINEARINTQUEUE_H
