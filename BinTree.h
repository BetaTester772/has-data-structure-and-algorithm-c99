//
// Created by hoseong on 2024-07-23.
//

#ifndef DATASTRUCTUREANDALGORITHM_BINTREE_H
#define DATASTRUCTUREANDALGORITHM_BINTREE_H

typedef struct __bnode {
    int data;
    struct __bnode *left;
    struct __bnode *right;
} BinNode;


BinNode *Search(BinNode *p, int x);

BinNode *Add(BinNode *p, int x);

int Remove(BinNode **root, int x);

void PrintTree(const BinNode *p);

void FreeTree(BinNode *p);

#endif //DATASTRUCTUREANDALGORITHM_BINTREE_H
