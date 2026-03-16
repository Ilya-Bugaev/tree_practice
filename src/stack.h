#pragma once
#include "bst.h"

typedef struct StackItem {
	Node* item;
	struct StackItem* nextStackItem;
} StackItem;

typedef struct Stack {
	StackItem* top;
	int size;
} Stack;

Stack* initStack();
void push(Stack* stack, Node* node);
Node* pop(Stack* stack);
void freeStack(Stack** stack);
