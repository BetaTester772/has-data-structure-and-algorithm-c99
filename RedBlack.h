//
// Created by hoseong on 2024-07-24.
//

#ifndef DATASTRUCTUREANDALGORITHM_REDBLACK_H
#define DATASTRUCTUREANDALGORITHM_REDBLACK_H

typedef enum {
    RED, BLACK
} Color;

typedef struct RBNode {
    int data;
    Color color;
    struct RBNode *left;
    struct RBNode *right;
    struct RBNode *parent;
} RBNode;

static RBNode *AllocRBNode(void);

static void SetRBNode(RBNode *n, int x, RBNode *left, RBNode *right, Color color);

RBNode *createNode(int key);

void insert(RBNode **root, int key);

void levelOrder(RBNode *root);


#endif //DATASTRUCTUREANDALGORITHM_REDBLACK_H
