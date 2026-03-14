#pragma once
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

typedef struct BST {
    Node* root;
} BST;

typedef enum Direction {
    LEFT,
    RIGHT
} Direction;

void bstInsert(BST* tree, int value);

bool bstContains(BST* tree, int value);

void bstFree(BST* tree);

void bstFreeNode(Node* node);