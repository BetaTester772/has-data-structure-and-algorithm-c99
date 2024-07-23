//
// Created by hoseong on 2024-07-24.
//

#include <stdio.h>
#include <stdlib.h>
#include "RedBlack.h"

static RBNode* AllocRBNode(void) {
    return calloc(1, sizeof(RBNode));
}

static void SetRBNode(RBNode* n, int x, RBNode* left, RBNode* right, Color color) {
    n->data = x;
    n->left = left;
    n->right = right;
    n->color = color;
}

RBNode* createNode(int key) {
    RBNode* node = AllocRBNode();
    SetRBNode(node, key, NULL, NULL, RED); // New nodes are always red initially
    return node;
}

RBNode* rotateLeft(RBNode* root, RBNode* node) {
    RBNode* rightChild = node->right;
    node->right = rightChild->left;

    if (rightChild->left != NULL) {
        rightChild->left->parent = node;
    }
    rightChild->parent = node->parent;

    if (node->parent == NULL) {
        root = rightChild;
    } else if (node == node->parent->left) {
        node->parent->left = rightChild;
    } else {
        node->parent->right = rightChild;
    }

    rightChild->left = node;
    node->parent = rightChild;

    return root;
}

RBNode* rotateRight(RBNode* root, RBNode* node) {
    RBNode* leftChild = node->left;
    node->left = leftChild->right;

    if (leftChild->right != NULL) {
        leftChild->right->parent = node;
    }
    leftChild->parent = node->parent;

    if (node->parent == NULL) {
        root = leftChild;
    } else if (node == node->parent->left) {
        node->parent->left = leftChild;
    } else {
        node->parent->right = leftChild;
    }

    leftChild->right = node;
    node->parent = leftChild;

    return root;
}

RBNode* insertFixup(RBNode* root, RBNode* node) {
    while (node != root && node->parent->color == RED) {
        if (node->parent == node->parent->parent->left) {
            RBNode* uncle = node->parent->parent->right;
            if (uncle != NULL && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    root = rotateLeft(root, node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                root = rotateRight(root, node->parent->parent);
            }
        } else {
            RBNode* uncle = node->parent->parent->left;
            if (uncle != NULL && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->left) {
                    node = node->parent;
                    root = rotateRight(root, node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                root = rotateLeft(root, node->parent->parent);
            }
        }
    }
    root->color = BLACK;
    return root;
}

void insert(RBNode** root, int key) {
    RBNode* node = createNode(key);
    RBNode* y = NULL;
    RBNode* x = *root;

    while (x != NULL) {
        y = x;
        if (node->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    node->parent = y;
    if (y == NULL) {
        *root = node;
    } else if (node->data < y->data) {
        y->left = node;
    } else {
        y->right = node;
    }

    *root = insertFixup(*root, node);
}

RBNode* minValueNode(RBNode* node) {
    RBNode* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

RBNode* deleteFixup(RBNode* root, RBNode* node, RBNode* parent) {
    while (node != root && (node == NULL || node->color == BLACK)) {
        if (node == parent->left) {
            RBNode* sibling = parent->right;
            if (sibling->color == RED) {
                sibling->color = BLACK;
                parent->color = RED;
                root = rotateLeft(root, parent);
                sibling = parent->right;
            }
            if ((sibling->left == NULL || sibling->left->color == BLACK) &&
                (sibling->right == NULL || sibling->right->color == BLACK)) {
                sibling->color = RED;
                node = parent;
                parent = node->parent;
            } else {
                if (sibling->right == NULL || sibling->right->color == BLACK) {
                    if (sibling->left != NULL) sibling->left->color = BLACK;
                    sibling->color = RED;
                    root = rotateRight(root, sibling);
                    sibling = parent->right;
                }
                sibling->color = parent->color;
                parent->color = BLACK;
                if (sibling->right != NULL) sibling->right->color = BLACK;
                root = rotateLeft(root, parent);
                node = root;
                break;
            }
        } else {
            RBNode* sibling = parent->left;
            if (sibling->color == RED) {
                sibling->color = BLACK;
                parent->color = RED;
                root = rotateRight(root, parent);
                sibling = parent->left;
            }
            if ((sibling->left == NULL || sibling->left->color == BLACK) &&
                (sibling->right == NULL || sibling->right->color == BLACK)) {
                sibling->color = RED;
                node = parent;
                parent = node->parent;
            } else {
                if (sibling->left == NULL || sibling->left->color == BLACK) {
                    if (sibling->right != NULL) sibling->right->color = BLACK;
                    sibling->color = RED;
                    root = rotateLeft(root, sibling);
                    sibling = parent->left;
                }
                sibling->color = parent->color;
                parent->color = BLACK;
                if (sibling->left != NULL) sibling->left->color = BLACK;
                root = rotateRight(root, parent);
                node = root;
                break;
            }
        }
    }
    if (node != NULL) node->color = BLACK;
    return root;
}

void levelOrder(RBNode* root) {
    if (root == NULL) {
        return;
    }

    RBNode* queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        RBNode* node = queue[front++];
        if (node != NULL) {
            printf("%d(%s) ", node->data, node->color == RED ? "R" : "B");
            queue[rear++] = node->left;
            queue[rear++] = node->right;
        } else {
            printf("NULL ");
        }
    }
    printf("\n");
}

int main() {
    RBNode* root = NULL;

    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 40);
    insert(&root, 50);
    insert(&root, 25);

    printf("RB 트리 구성 완료:\n");
    levelOrder(root);

    return 0;
}