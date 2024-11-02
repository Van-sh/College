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

int isIdentical(struct Node *root1, struct Node *root2) {
  if (root1 == NULL && root2 == NULL) {
    return 1;
  }
  if (root1 != NULL && root2 != NULL) {
    return (root1->data == root2->data) &&
           isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
  }
  return 0;
}

int main() {
  struct Node *root1 = newNode(1);
  root1->left = newNode(2);
  root1->right = newNode(3);
  root1->left->left = newNode(4);
  root1->left->right = newNode(5);

  struct Node *root2 = newNode(1);
  root2->left = newNode(2);
  root2->right = newNode(3);
  root2->left->left = newNode(4);
  root2->left->right = newNode(5);

  if (isIdentical(root1, root2)) {
    printf("The trees are identical.\n");
  } else {
    printf("The trees are not identical.\n");
  }

  return 0;
}