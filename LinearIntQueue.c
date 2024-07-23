//
// Created by hoseong on 2024-07-23.
//

#include <stdio.h>
#include <stdlib.h>
#include "LinearIntQueue.h"


int Initialize(LinearIntQueue *q, int max) {
    q->num = 0;
    if ((q->que = calloc(max, sizeof(int))) == NULL) {
        q->max = 0;
        return -1;
    }
    q->max = max;
    return 0;
}

int Enque(LinearIntQueue *q, int x) {
    if (q->num >= q->max) {
        return -1;
    } else {
        q->que[q->num++] = x;
        return 0;
    }
}

int Deque(LinearIntQueue *q, int *x) {
    if (q->num <= 0) {
        return -1;
    } else {
        *x = q->que[0];
        for (int i = 0; i < q->num - 1; i++) {
            q->que[i] = q->que[i + 1];
        }
        q->num--;
        return 0;
    }
}

int Peek(const LinearIntQueue *q, int *x) {
    if (q->num <= 0) {
        return -1;
    } else {
        *x = q->que[0];
        return 0;
    }
}

void Clear(LinearIntQueue *q) {
    q->num = 0;
}

int Capacity(const LinearIntQueue *q) {
    return q->max;
}

int Size(const LinearIntQueue *q) {
    return q->num;
}

int IsEmpty(const LinearIntQueue *q) {
    return q->num <= 0;
}

int IsFull(const LinearIntQueue *q) {
    return q->num >= q->max;
}

int Search(const LinearIntQueue *q, int x) {
    for (int i = 0; i < q->num; i++) {
        if (q->que[i] == x) {
            return i;
        }
    }
    return -1;
}

void Print(const LinearIntQueue *q) {
    for (int i = 0; i < q->num; i++) {
        printf("%d ", q->que[i]);
    }
    putchar('\n');
}

void Terminate(LinearIntQueue *q) {
    if (q->que != NULL) {
        free(q->que);
    }
    q->max = q->num = 0;
}
