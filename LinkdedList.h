//
// Created by hoseong on 2024-07-23.
//

#ifndef DATASTRUCTUREANDALGORITHM_LINKDEDLIST_H
#define DATASTRUCTUREANDALGORITHM_LINKDEDLIST_H

typedef struct __node {
    int data;
    struct __node *next;
} Node;

typedef struct {
    Node *head;
    Node *crnt;
} List;

void Initialize(List *list);

Node *Search(List *list, int x);

void InsertFront(List *list, int x);

void InsertRear(List *list, int x);

void RemoveFront(List *list);

void RemoveRear(List *list);

void RemoveCurrent(List *list);

void Clear(List *list);

void PrintCurrent(const List *list);

void Print(const List *list);

void Terminate(List *list);

#endif //DATASTRUCTUREANDALGORITHM_LINKDEDLIST_H
