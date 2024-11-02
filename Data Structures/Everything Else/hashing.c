#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Node {
  char *key;
  int value;
  struct Node *next;
} Node;

Node *hashTable[TABLE_SIZE];

int hash(char *key) {
  int hash = 0;
  for (int i = 0; key[i] != '\0'; i++) {
    hash += key[i];
  }
  return hash % TABLE_SIZE;
}

Node *createNode(char *key, int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->key = strdup(key);
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

void insert(char *key, int value) {
  int index = hash(key);
  Node *newNode = createNode(key, value);
  newNode->next = hashTable[index];
  hashTable[index] = newNode;
}

Node *search(char *key) {
  int index = hash(key);
  Node *current = hashTable[index];
  while (current != NULL) {
    if (strcmp(current->key, key) == 0) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

int main() {
  insert("apple", 1);
  insert("banana", 2);
  insert("cherry", 3);

  Node *found = search("banana");
  if (found != NULL) {
    printf("Found value: %i\n", found->value);
  } else {
    printf("Key not found.\n");
  }

  return 0;
}