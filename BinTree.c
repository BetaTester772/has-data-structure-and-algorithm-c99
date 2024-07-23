//
// Created by hoseong on 2024-07-23.
//

#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"

static BinNode *AllocBinNode(void) {
    return calloc(1, sizeof(BinNode));
}

static void SetBinNode(BinNode *n, int x, BinNode *left, BinNode *right) {
    n->data = x;
    n->left = left;
    n->right = right;
}

BinNode *Search(BinNode *p, int x) {
    int cond;
    if (p == NULL) {
        return NULL;
    } else if (x == p->data) {
        return p;
    } else if (x < p->data) {
        return Search(p->left, x);
    } else {
        return Search(p->right, x);
    }
}

BinNode *Add(BinNode *p, int x) {
    if (p == NULL) {
        p = AllocBinNode();
        SetBinNode(p, x, NULL, NULL);
    } else if (x == p->data) {
        printf("The data is already exist.\n");
    } else if (x < p->data) {
        p->left = Add(p->left, x);
    } else if (x > p->data) {
        p->right = Add(p->right, x);
    }
    return p;
}

int Remove(BinNode **root, int x) {
    BinNode *next, *temp;
    BinNode **left;
    BinNode **p = root;

    while (1) {
        int cond;
        if (*p == NULL) {
            printf("The data is not exist.\n");
            return -1;
        } else if (x == (*p)->data) {
            break;
        } else if (x < (*p)->data) {
            p = &((*p)->left);
        } else {
            p = &((*p)->right);
        }
    }
    if ((*p)->left == NULL) {
        next = (*p)->right;
    } else {
        left = &((*p)->left);
        while ((*left)->right != NULL) {
            left = &((*left)->right);
        }
        next = *left;
        *left = (*left)->left;
        next->left = (*p)->left;
        next->right = (*p)->right;
    }
    temp = *p;
    *p = next;
    free(temp);

    return 0;
}

void PrintTree(const BinNode *p) {
    if (p != NULL) {
        PrintTree(p->left);
        printf("%d ", p->data);
        PrintTree(p->right);
    }
}

void FreeTree(BinNode *p) {
    if (p != NULL) {
        FreeTree(p->left);
        FreeTree(p->right);
        free(p);
    }
}
