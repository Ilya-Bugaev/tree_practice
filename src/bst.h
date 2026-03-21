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

// Вставка значения в дерево
void bstInsert(BST* tree, int value);

// Проверка наличия значения в дереве
bool bstContains(BST* tree, int value);

// Освобождение памяти, занятой в дереве
void bstFree(BST* tree);

// Освобождение узла
void bstFreeNode(Node* node);

// Слияние двух деревьев
BST* bstMerge(BST* tree1, BST* tree2);

// Удаление узла из BST
void bstDelete(BST* tree, int value);