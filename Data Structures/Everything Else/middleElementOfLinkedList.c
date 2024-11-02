#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *newNode(int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

Node *middleNode(Node *head) {
  if (head == NULL) {
    return NULL;
  }

  Node *slow = head;
  Node *fast = head;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

int main() {
  Node *head = newNode(1);
  head->next = newNode(2);
  head->next->next = newNode(3);
  head->next->next->next = newNode(4);
  head->next->next->next->next = newNode(5);

  Node *middle = middleNode(head);

  if (middle != NULL) {
    printf("The middle element is %i\n", middle->data);
  } else {
    printf("The list is empty\n");
  }

  return 0;
}