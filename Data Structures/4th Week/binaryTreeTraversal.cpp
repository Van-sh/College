#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

void preorder(struct Node *node) {
  if (node != NULL) {
    printf("%i ", node->data);
    preorder(node->left);
    preorder(node->right);
  }
}

void inorder(struct Node *node) {
  if (node != NULL) {
    inorder(node->left);
    printf("%i ", node->data);
    inorder(node->right);
  }
}

void postorder(struct Node *node) {
  if (node != NULL) {
    postorder(node->left);
    postorder(node->right);
    printf("%i ", node->data);
  }
}

int main() {
  struct Node *root = (struct Node *)malloc(sizeof(struct Node));
  root->data = 1;
  root->left = (struct Node *)malloc(sizeof(struct Node));
  root->right = (struct Node *)malloc(sizeof(struct Node));
  root->left->data = 2;
  root->right->data = 3;
  root->left->left = (struct Node *)malloc(sizeof(struct Node));
  root->left->right = (struct Node *)malloc(sizeof(struct Node));
  root->left->left->data = 4;
  root->left->right->data = 5;
  root->left->left->left = root->left->left->right = NULL;
  root->left->right->left = root->left->right->right = NULL;
  root->right->left = root->right->right = NULL;

  printf("Preorder traversal: ");
  preorder(root);
  printf("\n");

  printf("Inorder traversal: ");
  inorder(root);
  printf("\n");

  printf("Postorder traversal: ");
  postorder(root);
  printf("\n");

  return 0;
}
