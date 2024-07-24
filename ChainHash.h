//
// Created by hoseo on 2024-07-24.
//

#ifndef DATASTRUCTUREANDALGORITHM_CHAINHASH_H
#define DATASTRUCTUREANDALGORITHM_CHAINHASH_H

typedef struct __node {
    int key;
    int value;
    struct __node *next;
} Node;

typedef struct {
    int size;
    Node **table;
} ChainHash;

int Initialize(ChainHash *h, int size);

Node *Search(const ChainHash *h, const int key);

int Add(ChainHash *h, const int key, const int value);

int Remove(ChainHash *h, const int key);

void Dump(const ChainHash *h);

void Clear(ChainHash *h);

void Terminate(ChainHash *h);

#endif //DATASTRUCTUREANDALGORITHM_CHAINHASH_H
