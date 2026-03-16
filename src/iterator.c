#include "iterator.h"
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct Iterator {
    Stack* stack;
} Iterator;

Iterator* iteratorInit(BST* tree)
{
    Iterator* iterator = malloc(sizeof(Iterator));
    Stack* stack = initStack();

    iterator->stack = stack;

    if (tree != NULL && tree->root != NULL) {
        push(iterator->stack, tree->root);
        pushAllLeft(iterator, tree->root);
    }

    return iterator;
}

static void pushAllLeft(Iterator* iterator, Node* node)
{
    if ((iterator == NULL) || (node == NULL)) {
        return;
    }

    Stack* stack = iterator->stack;

    while (node->leftChild != NULL) {
        node = node->leftChild;
        push(stack, node);
    }
}

bool iteratorHasNext(Iterator* iterator)
{
    return (iterator != NULL) && (iterator->stack->size > 0);
}

int iteratorNext(Iterator* iterator)
{
    if (iterator == NULL) {
        return ITERATOR_END_VALUE;
    }

    Stack* stack = iterator->stack;

    Node* node = pop(stack);

    if (node == NULL) {
        return ITERATOR_END_VALUE;
    }

    push(stack, node->rightChild);
    pushAllLeft(iterator, node->rightChild);

    return node->value;
}

void iteratorFree(Iterator** iterator)
{
    if (*iterator == NULL) {
        return;
    }

    Stack* stack = (*iterator)->stack;
    freeStack(&stack);

    free(*iterator);

    *iterator = NULL;
}