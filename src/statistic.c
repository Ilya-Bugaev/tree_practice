#include "iterator.h"

#include "statistic.h"

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