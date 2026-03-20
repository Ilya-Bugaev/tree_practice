#pragma once
#include "bst.h"

#define TREE_EMPTY_VALUE 0

int bstHeight(BST* tree);

int height(Node* node);

int bstSize(BST* tree);

int size(Node* node);

int bstMin(BST* tree); // функция от пустого дерева возвращает TREE_EMPTY_VALUE

int bstMax(BST* tree); // функция от пустого дерева возвращает TREE_EMPTY_VALUE