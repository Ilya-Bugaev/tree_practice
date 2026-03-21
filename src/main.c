#include "bst.h"
#include "checkBst.h"
#include "iterator.h"
#include "statistic.h"

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

    int k = 0;
    printf("K: %d MIN:%d\n", k, bstKthMin(tree, k));

    k = 5;
    printf("K: %d MIN:%d\n", k, bstKthMin(tree, k));

    k = 14;
    printf("K: %d MIN:%d\n", k, bstKthMin(tree, k));

    k = 15;
    printf("K: %d MIN:%d\n", k, bstKthMin(tree, k));

    printf("EMPTY: K: %d MIN:%d\n", k, bstKthMin(tree, k));
    printf("BST IS VALID: %d\n", bstIsValid(tree));
    tree->root->leftChild->leftChild->rightChild->leftChild->rightChild->value = 1000;
    iterator = iteratorInit(tree);

    while (iteratorHasNext(iterator)) {
        printf("%d ", iteratorNext(iterator));
    }
    printf("\n");

    iteratorFree(&iterator);

    printf("BST IS VALID: %d\n", bstIsValid(tree));

    BST* tree2 = malloc(sizeof(BST));
    tree2->root = malloc(sizeof(Node));
    tree2->root->value = 100;

    tree2->root->leftChild = malloc(sizeof(Node));
    tree2->root->leftChild->value = 99;

    printf("BST2 IS VALID: %d\n", bstIsValid(tree2));

    tree2->root->leftChild->value = 100;

    printf("BST2 IS VALID: %d\n", bstIsValid(tree2));

    tree2->root->rightChild = malloc(sizeof(Node));
    tree2->root->leftChild->value = 99;
    tree2->root->rightChild->value = 99;

    printf("BST2 IS VALID: %d\n", bstIsValid(tree2));

    tree2->root->rightChild->value = 999;

    printf("BST2 IS VALID: %d\n", bstIsValid(tree2));

    bstFree(tree);
    bstFree(tree2);
}