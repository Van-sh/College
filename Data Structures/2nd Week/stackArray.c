// 3. Implement a stack using an array
#include <stdio.h>
#define MAX_SIZE 5

void push(int stack[MAX_SIZE], int *top, int data) {
  if (*top == MAX_SIZE - 1) {
    printf("Stack Overflow\n");
    return;
  }
  (*top)++;
  stack[*top] = data;
  printf("%i was pushed into the stack\n", data);
}

void pop(int stack[MAX_SIZE], int *top) {
  if (*top == -1) {
    printf("Stack Underflow\n");
    return;
  }
  int data = stack[*top];
  (*top)--;
  printf("%i was popped from stack\n", data);
}

void display(int stack[MAX_SIZE], int top) {
  if (top == -1) {
    printf("Stack is Empty\n");
    return;
  }
  printf("Stack: ");
  for (int i = top; i >= 0; i--) {
    printf("%i ", stack[i]);
  }
  printf("\n");
}

int main() {
  int stack[MAX_SIZE];
  int top = -1;
  push(stack, &top, 10);
  push(stack, &top, 20);
  push(stack, &top, 30);
  push(stack, &top, 40);
  push(stack, &top, 50);
  push(stack, &top, 60);
  display(stack, top);
  pop(stack, &top);
  pop(stack, &top);
  pop(stack, &top);
  pop(stack, &top);
  pop(stack, &top);
  pop(stack, &top);
}