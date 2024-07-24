//
// Created by hoseong on 2024-07-24.
//

#include <stdio.h>
#include <stdlib.h>
#include "ChainHash.h"

static int hash(int key, int size) {
    return key % size;
}

static void SetNode(Node *n, int key, int value, Node *next) {
    n->key = key;
    n->value = value;
    n->next = next;
}

int Initialize(ChainHash *h, int size) {
    int i;
    if ((h->table = calloc(size, sizeof(Node *))) == NULL) {
        h->size = 0;
        return 0;
    }
    h->size = size;
    for (i = 0; i < size; i++) {
        h->table[i] = NULL;
    }
    return 1;
}

Node *Search(const ChainHash *h, const int key) {
    Node *p = h->table[hash(key, h->size)];
    while (p != NULL) {
        if (p->key == key) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

int Add(ChainHash *h, const int key, const int value) {
    int idx = hash(key, h->size);
    Node *p = h->table[idx];
    Node *temp;
    while (p != NULL) {
        if (p->key == key) {
            return 1;
        }
        p = p->next;
    }
    if ((temp = calloc(1, sizeof(Node))) == NULL) {
        return 2;
    }
    SetNode(temp, key, value, h->table[idx]);
    h->table[idx] = temp;
    return 0;
}

int Remove(ChainHash *h, const int key) {
    int idx = hash(key, h->size);
    Node *p = h->table[idx];
    Node *temp;
    Node **pp = &h->table[idx];
    while (p != NULL) {
        if (p->key == key) {
            *pp = p->next;
            free(p);
            return 0;
        }
        pp = &p->next;
        p = p->next;
    }
    return 1;
}

void Dump(const ChainHash *h) {
    int i;
    for (i = 0; i < h->size; i++) {
        Node *p = h->table[i];
        printf("%02d ", i);
        while (p != NULL) {
            printf("-> %d (%d) ", p->key, p->value);
            p = p->next;
        }
        putchar('\n');
    }
}

void Clear(ChainHash *h) {
    int i;
    for (i = 0; i < h->size; i++) {
        Node *p = h->table[i];
        while (p != NULL) {
            Node *next = p->next;
            free(p);
            p = next;
        }
        h->table[i] = NULL;
    }
}

void Terminate(ChainHash *h) {
    Clear(h);
    free(h->table);
    h->size = 0;
}