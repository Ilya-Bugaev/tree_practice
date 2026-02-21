#include "bst.h"
#include <stdio.h>
#include <stdlib.h>


void main()
{
    BST* tree = malloc(sizeof(BST));

    tree->root = NULL;


    bstInsert(tree, 6);

    bstInsert(tree, 4);
    bstInsert(tree, 5);

    printf("%d\n", tree->root->value);
    printf("%d\n", tree->root->leftChild->value);
    printf("%d\n", tree->root->leftChild->rightChild->value);
}