#pragma once
#include "bst.h"

#define ITERATOR_END_VALUE -32767

typedef struct Iterator Iterator;

Iterator* iteratorInit(BST* tree);
bool iteratorHasNext(Iterator* iterator);

// return ITERATOR_END_VALUE if iterator has not value
int iteratorNext(Iterator* iterator);

void iteratorFree(Iterator** iterator);

static void pushAllLeft(Iterator* iterator, Node* node);