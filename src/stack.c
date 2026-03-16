#include "stack.h"
#include <stdlib.h>
#include <stdio.h>



Stack* initStack() {
	Stack* stack = malloc(sizeof(Stack));
	stack->top = NULL;
	stack->size = 0;

	if (stack == NULL) {
		printf("NULL\n");
	}
	

	return stack;
}

void push(Stack* stack, Node* node) {
	if (node == NULL) {
		return;
	}
	
	StackItem* newStackItem = malloc(sizeof(StackItem));

	newStackItem->item = node;
	newStackItem->nextStackItem = stack->top;

	stack->top = newStackItem;
	stack->size++;

	// printf("%d HERE stack %d - value\n", stack->size, stack->top->item->value);
}



Node* pop(Stack* stack) {
	if (stack->top == NULL) {
		return NULL;
	}

	StackItem* out = stack->top;

	stack->top = out->nextStackItem;
	
	stack->size--;

	Node* node = out->item;
	
	free(out);

	return node;
}

void freeStack(Stack** stack) {
	if ((*stack)->top == NULL) {
		free(*stack);
		*stack = NULL;
		return;
	}

	while ((*stack)->size > 0) {
		pop(*stack);
	}

	(*stack)->top = NULL;
	
	free(*stack);
	*stack = NULL;
}


// void printStack(Stack* stack) {
//     if ((*stack).size == 0) {
//             printf("\n");
//                 return;
// 	}
// 	NodeList* current = (*stack).top;
// 	do {
// 			printf("%c ", (*current).value);
// 			current = (*current).next;
// 	}
// 	while (current != NULL);
// 	printf("\n");
// }
