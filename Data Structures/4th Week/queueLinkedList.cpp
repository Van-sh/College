#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Queue {
  struct Node *front;
  struct Node *rear;
};

struct Node *newNode(int data) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  return node;
}

struct Queue *createQueue() {
  struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
  queue->front = NULL;
  queue->rear = NULL;
  return queue;
}

void enqueue(struct Queue *queue, int data) {
  struct Node *node = newNode(data);
  if (queue->rear == NULL) {
    queue->front = node;
    queue->rear = node;
  } else {
    queue->rear->next = node;
    queue->rear = node;
  }
}

int dequeue(struct Queue *queue) {
  if (queue->front == NULL) {
    printf("Queue is empty\n");
    return -1;
  }
  int data = queue->front->data;
  queue->front = queue->front->next;
  if (queue->front == NULL) {
    queue->rear = NULL;
  }
  return data;
}

void displayQueue(struct Queue *queue) {
  if (queue->front == NULL) {
    printf("Queue is empty\n");
    return;
  }
  struct Node *temp = queue->front;
  while (temp != NULL) {
    printf("%i ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  struct Queue *queue = createQueue();
  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);

  printf("Queue elements: ");
  displayQueue(queue);

  int deletedElement = dequeue(queue);
  if (deletedElement != -1) {
    printf("Deleted element: %i\n", deletedElement);
  }

  printf("Queue elements after deletion: ");
  displayQueue(queue);

  return 0;
}