#include "bst.h"
#include "statistic.h"
#include <stdio.h>
#include <stdlib.h>

void main()
{
    BST* tree = malloc(sizeof(BST));\
    tree->root = NULL;

    bstInsert(tree, 6);
    bstInsert(tree, 4);
    bstInsert(tree, 5);
    bstInsert(tree, 7);
    bstInsert(tree, 9);
    bstInsert(tree, 11);
    bstInsert(tree, 2);
    bstInsert(tree, 1);

    /*printf("%d\n", tree->root->value);
    printf("%d\n", tree->root->leftChild->value);
    printf("%d\n", tree->root->leftChild->rightChild->value);*/

    printf("%d\n", bstMax(tree));
    printf("%d\n", bstMin(tree));
    printf("%d\n", bstHeight(tree));
    printf("%d\n", bstSize(tree));
    bstFree(tree);
}