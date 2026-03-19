#include "delete.h"
#include <stdlib.h>

void bstDelete(BST* tree, int value)
{
    if (tree == NULL || tree->root == NULL) {
        return;
    }

    Node* current = tree->root;
    Node* parent = NULL;

    while (current != NULL && current->value != value) {
        parent = current;
        if (value < current->value) {
            current = current->leftChild;
        } else {
            current = current->rightChild;
        }
    }

    if (current == NULL) {
        return;
    }

    if (current->leftChild == NULL || current->rightChild == NULL) {
        Node* child = (current->leftChild != NULL) ? current->leftChild : current->rightChild;

        if (parent == NULL) {
            tree->root = child;
        } else if (parent->leftChild == current) {
            parent->leftChild = child;
        } else {
            parent->rightChild = child;
        }

        free(current);
    } else {
        Node* successorParent = current;
        Node* successor = current->rightChild;

        while (successor->leftChild != NULL) {
            successorParent = successor;
            successor = successor->leftChild;
        }

        current->value = successor->value;

        if (successorParent == current) {
            successorParent->rightChild = successor->rightChild;
        } else {
            successorParent->leftChild = successor->rightChild;
        }
        free(successor);
    }
}