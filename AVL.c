// Created by hoseong on 2024-07-24.

#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

static AvlNode* AllocAvlNode(void) {
    return calloc(1, sizeof(AvlNode));
}

static void SetAvlNode(AvlNode* n, int x, AvlNode* left, AvlNode* right) {
    n->data = x;
    n->left = left;
    n->right = right;
    n->height = 1;
}

AvlNode* createNode(int key) {
    AvlNode* node = AllocAvlNode();
    SetAvlNode(node, key, NULL, NULL);
    return node;
}

int getHeight(AvlNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalance(AvlNode* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

AvlNode* rightRotate(AvlNode* y) {
    AvlNode* x = y->left;
    AvlNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));

    return x;
}

AvlNode* leftRotate(AvlNode* x) {
    AvlNode* y = x->right;
    AvlNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));

    return y;
}

AvlNode* insert(AvlNode* node, int key) {
    if (node == NULL)
        return createNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

AvlNode* minValueNode(AvlNode* node) {
    AvlNode* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

AvlNode* deleteNode(AvlNode* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            AvlNode* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;

            free(temp);
        } else {
            AvlNode* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + (getHeight(root->left) > getHeight(root->right) ? getHeight(root->left) : getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void levelOrder(AvlNode* root) {
    if (root == NULL)
        return;

    int front = 0, rear = 0;
    AvlNode* queue[100];

    queue[rear++] = root;

    while (front < rear) {
        AvlNode* current = queue[front++];

        if (current != NULL) {
            printf("%d ", current->data);

            if (current->left != NULL || current->right != NULL) {
                queue[rear++] = current->left;
                queue[rear++] = current->right;
            } else {
                queue[rear++] = NULL;
                queue[rear++] = NULL;
            }
        } else {
            printf("NULL ");
        }
    }
    printf("\n");
}

int main() {
    AvlNode* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("최초 AVL 트리:\n");
    levelOrder(root);

    root = deleteNode(root, 10);
    printf("\n10 삭제:\n");
    levelOrder(root);

    return 0;
}
