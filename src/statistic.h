#pragma once
#include "bst.h"

#define INCORRECT_K_VALUE -32767
#define TREE_EMPTY_VALUE 0

/*
 функция от пустого дерева возвращает TREE_EMPTY_VALUE == 0
 при некорректном k возвращает INCORRECT_K_VALUE == -32767
*/
int bstKthMin(BST* tree, int k);