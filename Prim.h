//
// Created by hoseong on 2024-07-24.
//

#ifndef DATASTRUCTUREANDALGORITHM_PRIM_H
#define DATASTRUCTUREANDALGORITHM_PRIM_H


#define MAX 1000
#define INF 9999999

typedef struct {
    int vertex;
    int weight;
    struct Node *next;
} Node;

typedef struct {
    int numVertices;
    __avl_node **adjLists;
    int *visited;
} Graph;

__avl_node *createNode(int v, int weight);

Graph *createGraph(int vertices);

void addEdge(Graph *graph, int src, int dest, int weight);

void primMST(Graph *graph);


#endif //DATASTRUCTUREANDALGORITHM_PRIM_H
