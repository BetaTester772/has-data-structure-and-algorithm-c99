//
// Created by hoseong on 2024-07-24.
//

#ifndef DATASTRUCTUREANDALGORITHM_KRUSKAL_H
#define DATASTRUCTUREANDALGORITHM_KRUSKAL_H

#define MAX 1000

typedef struct {
    int src, dest, weight;
} Edge;

typedef struct {
    int V, E;
    Edge *edges;
} Graph;

Graph *createGraph(int V, int E);

void addEdge(Graph *graph, int i, int src, int dest, int weight);

void kruskalMST(Graph *graph);

#endif //DATASTRUCTUREANDALGORITHM_KRUSKAL_H
