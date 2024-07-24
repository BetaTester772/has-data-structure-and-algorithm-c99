//
// Created by hoseong on 2024-07-24.
//

#include <stdio.h>
#include <stdlib.h>
#include "ClosedHash.h"

static int hash(int key, int size) {
    return key % size;
}

static int rehash(int key, int size) {
    return (key + 1) % size;
}

static void SetBucket(Bucket *n, int key, int value, Status status) {
    n->key = key;
    n->value = value;
    n->status = status;
}

int Initialize(ClosedHash *h, int size) {
    int i;
    if ((h->table = calloc(size, sizeof(Bucket))) == NULL) {
        h->size = 0;
        return 0;
    }
    h->size = size;
    for (i = 0; i < size; i++) {
        h->table[i].status = Empty;
    }
    return 1;
}

Bucket *Search(const ClosedHash *h, const int key) {
    int i, k;
    i = k = hash(key, h->size);
    do {
        if (h->table[i].status == Empty) {
            return NULL;
        } else if (h->table[i].status == Occupied && h->table[i].key == key) {
            return &h->table[i];
        }
        i = rehash(i, h->size);
    } while (i != k);
    return NULL;
}

int Add(ClosedHash *h, const int key, const int value) {
    int i, k;
    if (Search(h, key) != NULL) {
        return 1;
    }
    i = k = hash(key, h->size);
    do {
        if (h->table[i].status == Empty || h->table[i].status == Deleted) {
            SetBucket(&h->table[i], key, value, Occupied);
            return 0;
        }
        i = rehash(i, h->size);
    } while (i != k);
    return 2;
}

int Remove(ClosedHash *h, const int key) {
    Bucket *p = Search(h, key);
    if (p == NULL) {
        return 1;
    }
    p->status = Deleted;
    return 0;
}

void Dump(const ClosedHash *h) {
    int i;
    for (i = 0; i < h->size; i++) {
        printf("%02d : ", i);
        switch (h->table[i].status) {
            case Occupied:
                printf("%d (%d)\n", h->table[i].key, h->table[i].value);
                break;
            case Empty:
                printf("-- Empty --\n");
                break;
            case Deleted:
                printf("-- Deleted --\n");
                break;
        }
    }
}

void Clear(ClosedHash *h) {
    int i;
    for (i = 0; i < h->size; i++) {
        h->table[i].status = Empty;
    }
}

void Terminate(ClosedHash *h) {
    Clear(h);
    free(h->table);
    h->size = 0;
}