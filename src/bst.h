#include <stdbool.h>
#pragma onсe

typedef struct Node
{
    int value;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

typedef struct {
    Node* root;
} BST;

void bstInsert(BST* tree, int value);

bool bstContains(BST* tree, int value);

void bstFree(BST* tree);