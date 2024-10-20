#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct College {
  char name[50];
  int estdYear;
  struct College *next;
};

void insertAtFront(struct College **head, char name[], int estdYear) {
  struct College *newNode = (struct College *)malloc(sizeof(struct College));
  strcpy(newNode->name, name);
  newNode->estdYear = estdYear;
  newNode->next = NULL;
  if (*head == NULL) {
    *head = newNode;
    newNode->next = newNode;
  } else {
    newNode->next = *head;
    struct College *last = *head;
    while (last->next != *head) {
      last = last->next;
    }
    last->next = newNode;
    *head = newNode;
  }
}

void deleteAtEnd(struct College **head) {
  if (*head == NULL) {
    printf("List is empty!\n");
    return;
  } else if ((*head)->next == *head) {
    free(*head);
    *head = NULL;
  } else {
    struct College *current = *head;
    while (current->next->next != *head) {
      current = current->next;
    }
    free(current->next);
    current->next = *head;
  }
}

void displayList(struct College *head) {
  if (head == NULL) {
    printf("List is empty!\n");
    return;
  }
  struct College *current = head;
  do {
    printf("College Name: %s, Established Year: %i\n", current->name,
           current->estdYear);
    current = current->next;
  } while (current != head);
}

int main() {
  struct College *head = NULL;

  insertAtFront(&head, "MIT", 1861);
  insertAtFront(&head, "Harvard", 1636);
  insertAtFront(&head, "Stanford", 1885);

  printf("Circular Linked List (After insertions):\n");
  displayList(head);

  deleteAtEnd(&head);
  deleteAtEnd(&head);

  printf("\nCircular Linked List (After deletions):\n");
  displayList(head);

  return 0;
}