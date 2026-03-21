#include "bst.h"
#include "checkBst.h"
#include "inorder.h"
#include "iterator.h"
#include "statistic.h"
#include <stdio.h>
#include <stdlib.h>

void main()
{
    // A
    BST* tree = bstInit();
    bstInsert(tree, 6);
    bstInsert(tree, 4);
    bstInsert(tree, 5);
    bstInsert(tree, 7);
    bstInsert(tree, 9);
    bstInsert(tree, 11);
    bstInsert(tree, 2);
    bstInsert(tree, 1);

    printf("5: %d\n", bstContains(tree, 5));
    printf("123: %d\n", bstContains(tree, 123));

    bstFree(&tree);

    // B
    tree = bstInit();
    bstInsert(tree, 6);
    bstInsert(tree, 4);
    bstInsert(tree, 5);
    bstInsert(tree, 7);
    bstInsert(tree, 9);
    bstInsert(tree, 11);
    bstInsert(tree, 2);
    bstInsert(tree, 1);

    bstInorder(tree);
    bstPreorder(tree);
    bstPostorder(tree);

    // C
    printf("max: %d\n", bstMax(tree));
    printf("min: %d\n", bstMin(tree));
    printf("height: %d\n", bstHeight(tree));
    printf("size: %d\n", bstSize(tree));

    // D
    //  удаляем того, кто есть
    printf("5: %d\n", bstContains(tree, 5));
    bstDelete(tree, 5);
    printf("5: %d\n", bstContains(tree, 5));
    // удаляем того, кого нет
    printf("5: %d\n", bstContains(tree, 5));
    bstDelete(tree, 5);
    printf("5: %d\n", bstContains(tree, 5));

    // E
    BST* tree2 = bstInit();
    bstInsert(tree2, 13);
    bstInsert(tree2, 32);
    bstInsert(tree2, 57);
    bstInsert(tree2, 123);
    bstInsert(tree2, 111);
    bstInsert(tree2, 55);
    bstInsert(tree2, 23);
    bstInsert(tree2, 98);

    BST* treeRes = bstMerge(tree, tree2);
    bstInorder(treeRes);

    // F
    printf("BST treeRes IS VALID: %d\n", bstIsValid(treeRes));

    // G
    int k = 0;
    printf("K: %d MIN:%d\n", k, bstKthMin(tree, k));

    k = 5;
    printf("K: %d MIN:%d\n", k, bstKthMin(tree, k));

    k = 8;
    printf("K: %d MIN:%d\n", k, bstKthMin(tree, k));

    k = 9;
    printf("K: %d MIN:%d\n", k, bstKthMin(tree, k));

    bstFree(&tree);

    printf("EMPTY: K: %d MIN:%d\n", k, bstKthMin(tree, k));

    // H
    Iterator* iterator = iteratorInit(tree2);

    while (iteratorHasNext(iterator)) {
        printf("%d ", iteratorNext(iterator));
    }
    printf("\n");
    printf("%d\n", iteratorNext(iterator));

    iteratorFree(&iterator);

    bstFree(&tree2);
    bstFree(&treeRes);
}