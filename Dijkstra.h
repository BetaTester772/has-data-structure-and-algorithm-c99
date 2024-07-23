//
// Created by hoseong on 2024-07-24.
//

#ifndef DATASTRUCTUREANDALGORITHM_DIJKSTRA_H
#define DATASTRUCTUREANDALGORITHM_DIJKSTRA_H

#define MAX 1000
#define INF 9999999

typedef struct Node {
    int vertex;
    int weight;
    struct Node *next;
} Node;

typedef struct Graph {
    int numVertices;
    Node **adjLists;
    int *dist;
    int *prev;
} Graph;

Node *createNode(int v, int weight);

Graph *createGraph(int vertices);

void addEdge(Graph *graph, int src, int dest, int weight);

void dijkstra(Graph *graph, int startVertex);


#endif //DATASTRUCTUREANDALGORITHM_DIJKSTRA_H
