//
// Created by hoseong on 2024-07-23.
//

#ifndef DATASTRUCTUREANDALGORITHM_DFS_H
#define DATASTRUCTUREANDALGORITHM_DFS_H

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

Node *createNode(int v);

Graph *createGraph(int vertices);

void addEdge(Graph *graph, int s, int d);

void dfs(Graph *graph, int vertex);

#endif //DATASTRUCTUREANDALGORITHM_DFS_H
