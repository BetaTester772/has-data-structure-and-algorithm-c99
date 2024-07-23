//
// Created by hoseong on 2024-07-23.
//

#ifndef DATASTRUCTUREANDALGORITHM_RINGINTQUEUE_H
#define DATASTRUCTUREANDALGORITHM_RINGINTQUEUE_H

typedef struct {
    int max;
    int num;
    int front;
    int rear;
    int *que;
} RingIntQueue;

int Initialize(RingIntQueue *q, int max);

int Enque(RingIntQueue *q, int x);

int Deque(RingIntQueue *q, int *x);

int Peek(const RingIntQueue *q, int *x);

void Clear(RingIntQueue *q);

int Capacity(const RingIntQueue *q);

int Size(const RingIntQueue *q);

int IsEmpty(const RingIntQueue *q);

int IsFull(const RingIntQueue *q);

int Search(const RingIntQueue *q, int x);

void Print(const RingIntQueue *q);

void Terminate(RingIntQueue *q);

#endif //DATASTRUCTUREANDALGORITHM_RINGINTQUEUE_H
