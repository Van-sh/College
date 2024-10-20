#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
  int id;
  char name[50];
  float salary;
  struct Employee *prev;
  struct Employee *next;
};

void insertAtFront(struct Employee **head, int id, char *name, float salary) {
  struct Employee *newNode = (struct Employee *)malloc(sizeof(struct Employee));
  newNode->id = id;
  strcpy(newNode->name, name);
  newNode->salary = salary;
  newNode->prev = NULL;
  if (*head == NULL) {
    *head = newNode;
    return;
  }
  newNode->next = *head;
  (*head)->prev = newNode;
  *head = newNode;
}

void deleteAtEnd(struct Employee **head) {
  if (*head == NULL) {
    printf("List is empty\n");
    return;
  }
  struct Employee *temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  if (temp->prev != NULL) {
    temp->prev->next = NULL;
  } else {
    *head = NULL;
  }
  free(temp);
}

void printList(struct Employee *head) {
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }
  printf("Employee Details:\n");
  struct Employee *temp = head;
  while (temp != NULL) {
    printf("ID: %i, Name: %s, Salary: %.2f\n", temp->id, temp->name,
           temp->salary);
    temp = temp->next;
  }
}

int main() {
  struct Employee *head = NULL;

  insertAtFront(&head, 1, "Ram", 50000.00);
  insertAtFront(&head, 2, "Vishal", 60000.00);

  printf("List after insertion at front:\n");
  printList(head);

  deleteAtEnd(&head);

  printf("List after deletion at end:\n");
  printList(head);

  return 0;
}