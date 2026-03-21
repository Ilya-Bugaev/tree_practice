#include "bst.h"

#include "iterator.h"
#include "statistic.h"
#include <stdlib.h>

int bstHeight(BST* tree)
{
    if (tree == NULL || tree->root == NULL) {
        return 0;
    }

    return height(tree->root);
}

int height(Node* node)
{
    if (node == NULL) {
        return 0;
    }

    int leftHeight = height(node->leftChild);
    int rightHeight = height(node->rightChild);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int bstSize(BST* tree)
{
    if (tree == NULL || tree->root == NULL) {
        return 0;
    }

    return size(tree->root);
}

int size(Node* node)
{
    if (node == NULL) {
        return 0;
    }

    return 1 + size(node->leftChild) + size(node->rightChild);
}

int bstMin(BST* tree)
{
    if (tree == NULL || tree->root == NULL) {
        return TREE_EMPTY_VALUE;
    }

    Node* node = tree->root;
    while (node->leftChild != NULL) {
        node = node->leftChild;
    }
    return node->value;
}

int bstMax(BST* tree)
{
    if (tree == NULL || tree->root == NULL) {
        return TREE_EMPTY_VALUE;
    }

    Node* node = tree->root;
    while (node->rightChild != NULL) {
        node = node->rightChild;
    }
    return node->value;

int bstKthMin(BST* tree, int k)
{
    if ((tree == 0) || (tree->root == 0)) {
        return TREE_EMPTY_VALUE;
    }

    if (k <= 0) {
        return INCORRECT_K_VALUE;
    }

    Iterator* iterator = iteratorInit(tree);

    int index = 1;
    while (iteratorHasNext(iterator)) {
        int value = iteratorNext(iterator);

        if (index == k) {
            iteratorFree(&iterator);
            return value;
        }

        index++;
    }

    iteratorFree(&iterator);

    return INCORRECT_K_VALUE;
}