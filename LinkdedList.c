//
// Created by hoseong on 2024-07-23.
//
#include <stdio.h>
#include <stdlib.h>
#include "LinkdedList.h"

static __avl_node *AllocNode(void) {
    return calloc(1, sizeof(__avl_node));
}

void Initialize(List *list) {
    list->head = NULL;
    list->crnt = NULL;
}

__avl_node *Search(List *list, int x) {
    __avl_node *ptr = list->head;
    while (ptr != NULL) {
        if (ptr->data == x) {
            list->crnt = ptr;
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

void InsertFront(List *list, int x) {
    __avl_node *ptr = list->head;
    list->head = list->crnt = AllocNode();
    list->head->data = x;
    list->head->next = ptr;
}

void InsertRear(List *list, int x) {
    if (list->head == NULL) {
        InsertFront(list, x);
    } else {
        __avl_node *ptr = list->head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = list->crnt = AllocNode();
        ptr->next->data = x;
    }
}

void RemoveFront(List *list) {
    if (list->head != NULL) {
        __avl_node *ptr = list->head->next;
        free(list->head);
        list->head = list->crnt = ptr;
    }
}

void RemoveRear(List *list) {
    if (list->head != NULL) {
        if ((list->head)->next == NULL) {
            RemoveFront(list);
        } else {
            __avl_node *ptr = list->head;
            __avl_node *pre;
            while (ptr->next != NULL) {
                pre = ptr;
                ptr = ptr->next;
            }
            pre->next = NULL;
            free(ptr);
            list->crnt = pre;
        }
    }
}

void RemoveCurrent(List *list) {
    if (list->head != NULL) {
        if (list->crnt == list->head) {
            RemoveFront(list);
        } else {
            __avl_node *ptr = list->head;
            while (ptr->next != list->crnt) {
                ptr = ptr->next;
            }
            ptr->next = list->crnt->next;
            free(list->crnt);
            list->crnt = ptr;
        }
    }
}

void Clear(List *list) {
    while (list->head != NULL) {
        RemoveFront(list);
    }
    list->crnt = NULL;
}

void PrintCurrent(const List *list) {
    if (list->crnt == NULL) {
        printf("선택한 노드가 없습니다.");
    } else {
        printf("%d", list->crnt->data);
    }
}

void Print(const List *list) {
    if (list->head == NULL) {
        puts("노드가 없습니다.");
    } else {
        __avl_node *ptr = list->head;
        puts("각 노드의 데이터를 출력합니다.");
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}

void Terminate(List *list) {
    Clear(list);
}