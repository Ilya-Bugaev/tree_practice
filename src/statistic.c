#include "bst.h"

#include "statistic.h"
#include <stdlib.h>

int bstHeight(BST* tree)
{
    if (tree == NULL || tree->root == NULL) {
        return 0;
    }

    return height(tree->root);
}

int height(Node* root)
{
    if (root == NULL) {
        return 0;
    }

    int left_height = height(root->leftChild);
    int right_height = height(root->rightChild);
    return 1 + (left_height > right_height ? left_height : right_height);
}

int bstSize(BST* tree)
{
    if (tree == NULL || tree->root == NULL) {
        return 0;
    }

    return size(tree->root);
}

int size(Node* root)
{
    if (root == NULL) {
        return 0;
    }

    return 1 + size(root->leftChild) + size(root->rightChild);
}

int bstMin(BST* tree)
{
    if (tree == NULL || tree->root == NULL) {
        return 0;
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
        return 0;
    }

    Node* node = tree->root;
    while (node->rightChild != NULL) {
        node = node->rightChild;
    }
    return node->value;
}