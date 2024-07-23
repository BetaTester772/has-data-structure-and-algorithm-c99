//
// Created by hoseong on 2024-07-24.
//

#ifndef DATASTRUCTUREANDALGORITHM_AVL_H
#define DATASTRUCTUREANDALGORITHM_AVL_H

typedef struct __anode {
    int data;
    struct __anode *left;
    struct __anode *right;
    int height;
} AvlNode;

static AvlNode *AllocAvlNode(void);

static void SetAvlNode(AvlNode *n, int x, AvlNode *left, AvlNode *right);

AvlNode *createNode(int key);

int getHeight(AvlNode *node);

int getBalance(AvlNode *node);

AvlNode *rightRotate(AvlNode *y);

AvlNode *leftRotate(AvlNode *x);

AvlNode *insert(AvlNode *node, int key);

AvlNode *minValueNode(AvlNode *node);

AvlNode *deleteNode(AvlNode *root, int key);

void levelOrder(AvlNode *root);


#endif //DATASTRUCTUREANDALGORITHM_AVL_H
