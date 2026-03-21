#pragma once
#include "bst.h"

#define TREE_EMPTY_VALUE 0
#define INCORRECT_K_VALUE -32767

int bstHeight(BST* tree);

int height(Node* node);

int bstSize(BST* tree);

int size(Node* node);

int bstMin(BST* tree); // функция от пустого дерева возвращает TREE_EMPTY_VALUE

int bstMax(BST* tree); // функция от пустого дерева возвращает TREE_EMPTY_VALUE

/*
 функция от пустого дерева возвращает TREE_EMPTY_VALUE == 0
 при некорректном k возвращает INCORRECT_K_VALUE == -32767
*/
int bstKthMin(BST* tree, int k);