#include "bst.h"
#include "iterator.h"

#include <stdio.h>
#include <stdlib.h>

void main()
{
    BST* tree = malloc(sizeof(BST));

    tree->root = NULL;

    bstInsert(tree, 100);
    bstInsert(tree, 60);
    bstInsert(tree, 50);
    bstInsert(tree, 30);
    bstInsert(tree, 57);
    bstInsert(tree, 55);
    bstInsert(tree, 52);
    bstInsert(tree, 56);
    bstInsert(tree, 54);
    bstInsert(tree, 53);
    bstInsert(tree, 200);
    bstInsert(tree, 10);
    bstInsert(tree, 9);
    bstInsert(tree, 1);

    Iterator* iterator = iteratorInit(tree);

    while (iteratorHasNext(iterator)) {
        printf("%d ", iteratorNext(iterator));
    }
    printf("\n");
    printf("%d\n", iteratorNext(iterator));

    iteratorFree(&iterator);
    bstFree(tree);
}