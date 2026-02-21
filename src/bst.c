#include "bst.h"
#include <stdlib.h>

void bstInsert(BST* tree, int value)
{
    Node* root = tree->root;
    Node* prev = NULL;
    bool isLeft = true;

    while(root != NULL) {
        int curValue = root->value;
        if (curValue == value) {
            return;
        }
        prev = root;
        if (curValue > value) {
            root = root->leftChild;
            isLeft = true;
        } else if (curValue < value) {
            root = root->rightChild;
            isLeft = false;
        }
    }

    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    if (prev == NULL) {
        tree->root = newNode;
    } else {
        if (isLeft) {
            prev->leftChild = newNode;

        } else {
            prev->rightChild = newNode;
        }
    }
}