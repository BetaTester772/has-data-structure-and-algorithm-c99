//
// Created by hoseong on 2024-07-24.
//

#ifndef DATASTRUCTUREANDALGORITHM_FLOYD_H
#define DATASTRUCTUREANDALGORITHM_FLOYD_H

#define MAX 100
#define INF 9999999

typedef struct {
    int numVertices;
    int dist[MAX][MAX];
    int next[MAX][MAX];
} Graph;

Graph *createGraph(int vertices);

void addEdge(Graph *graph, int src, int dest, int weight);

void floydWarshall(Graph *graph);

void printSolution(Graph *graph);


#endif //DATASTRUCTUREANDALGORITHM_FLOYD_H
