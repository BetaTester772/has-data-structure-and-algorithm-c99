//
// Created by hoseong on 2024-07-23.
//

#ifndef DATASTRUCTUREANDALGORITHM_BFS_H
#define DATASTRUCTUREANDALGORITHM_BFS_H

#define MAX 1000

typedef struct {
    int vertex;
    struct Node *link;
} Node;

typedef struct {
    int numVertices;
    Node **adjLists;
    int *visited;
} Graph;

typedef struct {
    int front;
    int rear;
    int items[MAX];
} Queue;

Node *createNode(int v);

Graph *createGraph(int vertices);

void addEdge(Graph *graph, int s, int d);

void bfs(Graph *graph, int startVertex);

Queue *createQueue();

int isEmpty(Queue *q);

void enQueue(Queue *q, int value);

int deQueue(Queue *q);


#endif //DATASTRUCTUREANDALGORITHM_BFS_H
