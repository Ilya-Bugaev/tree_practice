#include "inorder.h"
#include "bst.h"
#include <stdio.h>

void recInorder(Node *node) {
  if (node == NULL) {
    return;
  }

  recInorder(node->leftChild);
  printf("%d ", node->value);
  recInorder(node->rightChild);
}

void recPreorder(Node *node) {
  if (node == NULL) {
    return;
  }

  printf("%d ", node->value);
  recPreorder(node->leftChild);
  recPreorder(node->rightChild);
}

void recPostorder(Node *node) {
  if (node == NULL) {
    return;
  }

  recPostorder(node->leftChild);
  recPostorder(node->rightChild);
  printf("%d ", node->value);
}

void bstInorder(BST *tree) {
  if (tree == NULL) {
    return;
  }

  recInorder(tree->root);
  printf("\n");
}

void bstPreorder(BST *tree) {
  if (tree == NULL) {
    return;
  }

  recPreorder(tree->root);
  printf("\n");
}

void bstPostorder(BST *tree) {
  if (tree == NULL) {
    return;
  }

  recPostorder(tree->root);
  printf("\n");
}
