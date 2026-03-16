#include "checkBst.h"
#include "iterator.h"

bool bstIsValid(BST* tree)
{
    if ((tree == 0) || (tree->root == 0)) {
        return true;
    }

    Iterator* iterator = iteratorInit(tree);

    int prevValue = iteratorNext(iterator);
    int currValue = 0;

    if (!iteratorHasNext(iterator)) {
        iteratorFree(&iterator);
        return true;
    }

    while (iteratorHasNext(iterator)) {
        currValue = iteratorNext(iterator);

        if (currValue <= prevValue) {
            iteratorFree(&iterator);
            return false;
        }

        prevValue = currValue;
    }

    iteratorFree(&iterator);
    return true;
}