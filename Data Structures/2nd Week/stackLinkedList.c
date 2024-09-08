// 3. Implement a stack using a linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void push(struct Node **top, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (newNode == NULL) {
    printf("Memory allocation failed\n");
    return;
  }
  newNode->data = data;
  newNode->next = *top;
  *top = newNode;
  printf("%i was pushed into the stack\n", data);
}

void pop(struct Node **top) {
  if (*top == NULL) {
    printf("Stack Underflow\n");
    return;
  }
  struct Node *temp = *top;
  int data = temp->data;
  *top = (*top)->next;
  free(temp);
  printf("%i was popped from stack\n", data);
}

void display(struct Node *top) {
  if (top == NULL) {
    printf("Stack is Empty\n");
    return;
  }
  printf("Stack: ");
  struct Node *temp = top;
  while (temp != NULL) {
    printf("%i ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  struct Node *top = NULL;
  push(&top, 10);
  push(&top, 20);
  push(&top, 30);
  push(&top, 40);
  push(&top, 50);
  display(top);
  pop(&top);
  pop(&top);
  pop(&top);
  pop(&top);
  pop(&top);
  pop(&top);
}