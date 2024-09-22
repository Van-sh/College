// 5. Create a linked list with nodes having information about a student and perform
// a. Insert a new node at specified position.
// b. Delete of a node with the roll number of student specified.
// c. Reversal of that linked list,
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int rollNumber;
  char *name;
  struct Node *next;
};

struct Node *head = NULL;

void insert(int rollNumber, char *name, int position) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->rollNumber = rollNumber;
  newNode->name = name;
  if (position == 0) {
    newNode->next = head;
    head = newNode;
    return;
  }
  struct Node *current = head;
  int count = 0;
  while (current != NULL && count < position - 1) {
    current = current->next;
    count++;
  }
  if (current == NULL) {
    printf("Invalid position\n");
    return;
  }
  newNode->next = current->next;
  current->next = newNode;
}

void delete (int rollNumber) {
  struct Node *current = head;
  struct Node *previous = NULL;
  while (current != NULL) {
    if (current->rollNumber == rollNumber) {
      if (previous == NULL) {
        head = current->next;
      } else {
        previous->next = current->next;
      }
      char *deleted = current->name;
      free(current);
      printf("%s deleted from the linked list.\n", deleted);
      return;
    }
    previous = current;
    current = current->next;
  }
  printf("Roll Number not found in the linked list.\n");
}
void reverseList() {
  struct Node *previous = NULL;
  struct Node *current = head;
  struct Node *next = NULL;
  while (current != NULL) {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }
  head = previous;
}

void printList() {
  struct Node *current = head;
  while (current != NULL) {
    printf("%d: %s", current->rollNumber, current->name);
    if (current->next != NULL)
      printf(" -> ");
    current = current->next;
  }
  printf("\n");
}
int main(void) {
  insert(2, "Ravi", 0);
  insert(3, "Shubham", 1);
  insert(1, "Ram", 0);
  printList();
  printf("Reversing the list...\n");
  reverseList();
  printList();
  delete (2);
  printList();
  return 0;
}