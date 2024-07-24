//
// Created by hoseong on 2024-07-24.
//

#include <stdio.h>
#include "BinTree.h"

int main(void) {
    BinNode *root = NULL;
    BinNode *result;
    int searchValue;

    root = Add(root, 50);
    root = Add(root, 30);
    root = Add(root, 70);
    root = Add(root, 20);
    root = Add(root, 40);
    root = Add(root, 60);
    root = Add(root, 80);

    printf("Binary Search Tree (In-Order): ");
    PrintTree(root);
    printf("\n");

    printf("Enter the value to search: ");
    scanf("%d", &searchValue);

    result = Search(root, searchValue);
    if (result != NULL) {
        printf("Value %d found in the tree.\n", searchValue);
    } else {
        printf("Value %d not found in the tree.\n", searchValue);
    }

    FreeTree(root);

    return 0;
}