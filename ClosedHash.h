//
// Created by hoseo on 2024-07-24.
//

#ifndef DATASTRUCTUREANDALGORITHM_CLOSEDHASH_H
#define DATASTRUCTUREANDALGORITHM_CLOSEDHASH_H

typedef enum {
    Occupied, Empty, Deleted
} Status;

typedef struct {
    int key;
    int value;
    Status status;
} Bucket;

typedef struct {
    int size;
    Bucket *table;
} ClosedHash;

int Initialize(ClosedHash *h, int size);

Bucket *Search(const ClosedHash *h, const int key);

int Add(ClosedHash *h, const int key, const int value);

int Remove(ClosedHash *h, const int key);

void Dump(const ClosedHash *h);

void Clear(ClosedHash *h);

void Terminate(ClosedHash *h);

#endif //DATASTRUCTUREANDALGORITHM_CLOSEDHASH_H
