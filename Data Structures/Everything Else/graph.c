#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct AdjListNode {
  int dest;
  struct AdjListNode *next;
} AdjListNode;

typedef struct AdjList {
  AdjListNode *head;
} AdjList;

typedef struct Graph {
  int V;
  AdjList *array;
} Graph;

AdjListNode *newAdjListNode(int dest) {
  AdjListNode *newNode = (AdjListNode *)malloc(sizeof(AdjListNode));
  newNode->dest = dest;
  newNode->next = NULL;
  return newNode;
}

Graph *createGraph(int V) {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->V = V;
  graph->array = (AdjList *)malloc(V * sizeof(AdjList));
  for (int i = 0; i < V; ++i) {
    graph->array[i].head = NULL;
  }
  return graph;
}

void addEdge(Graph *graph, int src, int dest) {
  AdjListNode *newNode = newAdjListNode(dest);
  newNode->next = graph->array[src].head;
  graph->array[src].head = newNode;

  newNode = newAdjListNode(src);
  newNode->next = graph->array[dest].head;
  graph->array[dest].head = newNode;
}

void BFS(Graph *graph, int start) {
  int visited[MAX_VERTICES] = {0};
  int queue[MAX_VERTICES];
  int front = 0, rear = 0;

  visited[start] = 1;
  queue[rear++] = start;

  while (front != rear) {
    int current = queue[front++];

    printf("%i ", current);

    AdjListNode *temp = graph->array[current].head;
    while (temp != NULL) {
      if (!visited[temp->dest]) {
        visited[temp->dest] = 1;
        queue[rear++] = temp->dest;
      }
      temp = temp->next;
    }
  }
}

void DFSUtil(Graph *graph, int start, int visited[]) {
  visited[start] = 1;

  printf("%i ", start);

  AdjListNode *temp = graph->array[start].head;
  while (temp != NULL) {
    if (!visited[temp->dest]) {
      DFSUtil(graph, temp->dest, visited);
    }
    temp = temp->next;
  }
}

void DFS(Graph *graph, int start) {
  int visited[MAX_VERTICES] = {0};

  DFSUtil(graph, start, visited);
}

int main() {
  Graph *graph = createGraph(5);

  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 4);

  printf("Following is Breadth First Traversal (starting from vertex 0):\n");
  BFS(graph, 0);

  printf("\nFollowing is Depth First Traversal (starting from vertex 0):\n");
  DFS(graph, 0);

  return 0;
}