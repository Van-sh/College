#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  char type[50];
  char company[50];
  int year;
  struct Node *left;
  struct Node *right;
};

struct Node *insert(struct Node *node, char *type, char *company, int year) {
  if (node == NULL) {
    node = (struct Node *)malloc(sizeof(struct Node));
    strcpy(node->type, type);
    strcpy(node->company, company);
    node->year = year;
    node->left = NULL;
    node->right = NULL;
    return node;
  }

  if (year < node->year) {
    node->left = insert(node->left, type, company, year);
  } else if (year > node->year) {
    node->right = insert(node->right, type, company, year);
  }

  return node;
}

void inorder(struct Node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("Type: %s, Company: %s, Year: %d\n", root->type, root->company,
           root->year);
    inorder(root->right);
  }
}

void preorder(struct Node *root) {
  if (root != NULL) {
    printf("Type: %s, Company: %s, Year: %d\n", root->type, root->company,
           root->year);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(struct Node *root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("Type: %s, Company: %s, Year: %d\n", root->type, root->company,
           root->year);
  }
}

struct Node *findMin(struct Node *node) {
  while (node->left != NULL) {
    node = node->left;
  }
  return node;
}

struct Node *deleteNode(struct Node *root, int year) {
  if (root == NULL) {
    return root;
  }

  if (year < root->year) {
    root->left = deleteNode(root->left, year);
  } else if (year > root->year) {
    root->right = deleteNode(root->right, year);
  } else {
    if (root->left == NULL) {
      struct Node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct Node *temp = root->left;
      free(root);
      return temp;
    }

    struct Node *temp = findMin(root->right);

    strcpy(root->type, temp->type);
    strcpy(root->company, temp->company);
    root->year = temp->year;

    root->right = deleteNode(root->right, temp->year);
  }
  return root;
}

int main() {
  struct Node *root = NULL;

  root = insert(root, "Sedan", "Toyota", 2020);
  root = insert(root, "SUV", "Honda", 2021);
  root = insert(root, "Hatchback", "Ford", 2019);

  printf("Inorder traversal: \n");
  inorder(root);

  printf("\nPreorder traversal: \n");
  preorder(root);

  printf("\nPostorder traversal: \n");
  postorder(root);

  printf("\nDeleting node with year 2020\n");
  root = deleteNode(root, 2020);

  printf("\nInorder traversal after deletion: \n");
  inorder(root);

  return 0;
}
