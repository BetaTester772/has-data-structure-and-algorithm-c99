//
// Created by hoseong on 2024-07-23.
//

#include <stdio.h>
#include <stdlib.h>
#include "RingIntQueue.h"

int Initialize(RingIntQueue *q, int max) {
    q->num = q->front = q->rear = 0;
    if ((q->que = calloc(max, sizeof(int))) == NULL) {
        q->max = 0;
        return -1;
    }
    q->max = max;
    return 0;
}

int Enque(RingIntQueue *q, int x) {
    if (q->num >= q->max) {
        return -1;
    }
    q->num++;
    q->que[q->rear++] = x;
    if (q->rear == q->max) {
        q->rear = 0;
    }
    return 0;
}

int Deque(RingIntQueue *q, int *x) {
    if (q->num <= 0) {
        return -1;
    }
    q->num--;
    *x = q->que[q->front++];
    if (q->front == q->max) {
        q->front = 0;
    }
    return 0;
}

int Peek(const RingIntQueue *q, int *x) {
    if (q->num <= 0) {
        return -1;
    }
    *x = q->que[q->front];
    return 0;
}

void Clear(RingIntQueue *q) {
    q->num = q->front = q->rear = 0;
}

int Capacity(const RingIntQueue *q) {
    return q->max;
}

int Size(const RingIntQueue *q) {
    return q->num;
}

int IsEmpty(const RingIntQueue *q) {
    return q->num <= 0;
}

int IsFull(const RingIntQueue *q) {
    return q->num >= q->max;
}

int Search(const RingIntQueue *q, int x) {
    for (int i = 0; i < q->num; i++) {
        if (q->que[(i + q->front) % q->max] == x) {
            return i;
        }
    }
    return -1;
}

void Print(const RingIntQueue *q) {
    for (int i = 0; i < q->num; i++) {
        printf("%d ", q->que[(i + q->front) % q->max]);
    }
    putchar('\n');
}

void Terminate(RingIntQueue *q) {
    if (q->que != NULL) {
        free(q->que);
    }
    q->max = q->num = q->front = q->rear = 0;
}