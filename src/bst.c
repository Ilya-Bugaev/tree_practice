#include "bst.h"
#include <stdlib.h>

void bstInsert(BST *tree, int value)
{
    if (tree == NULL)
    {
        return;
    }

    Node *root = tree->root;
    Node *prev = NULL;
    Direction dir;

    while (root != NULL)
    {
        int curValue = root->value;
        if (curValue == value)
        {
            return;
        }
        prev = root;
        if (curValue > value)
        {
            root = root->leftChild;
            dir = LEFT;
        }
        else if (curValue < value)
        {
            root = root->rightChild;
            dir = RIGHT;
        }
    }

    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return;
    }

    newNode->value = value;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    if (prev == NULL)
    {
        tree->root = newNode;
    }
    else
    {
        if (dir == LEFT)
        {
            prev->leftChild = newNode;
        }
        else
        {
            prev->rightChild = newNode;
        }
    }
}

bool bstContains(BST *tree, int value)
{
    if (tree == NULL)
    {
        return false;
    }
    Node *current = tree->root;
    while (current != NULL)
    {
        int curValue = current->value;
        if (curValue == value)
        {
            return true;
        }
        if (curValue > value)
        {
            current = current->leftChild;
        }
        else if (curValue < value)
        {
            current = current->rightChild;
        }
    }
    return false;
}

void bstFree(BST *tree)
{
    if (tree == NULL)
    {
        return;
    }

    Node *root = tree->root;

    if (root == NULL)
    {
        free(tree);
        return;
    }

    bstFreeNode(root);
    free(tree);
}

void bstFreeNode(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    bstFreeNode(node->leftChild);
    bstFreeNode(node->rightChild);
    free(node);
}