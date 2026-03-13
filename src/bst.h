#pragma onсe
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

typedef struct {
    Node* root;
} BST;

enum Direction {LEFT, RIGHT};

void bstInsert(BST* tree, int value);

bool bstContains(BST* tree, int value);

void bstFree(BST* tree);