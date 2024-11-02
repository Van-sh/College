#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node *newNode(int data) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

int height(struct Node *node) {
  if (node == NULL) {
    return 0;
  } else {
    int lheight = height(node->left);
    int rheight = height(node->right);
    if (lheight > rheight) {
      return (lheight + 1);
    } else {
      return (rheight + 1);
    }
  }
}

int main() {
  struct Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);

  printf("Height of the tree is %d\n", height(root));

  return 0;
}