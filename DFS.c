//
// Created by hoseong on 2024-07-23.
//

#include <stdio.h>
#include <stdlib.h>
#include "DFS.h"

//typedef struct {
//    int vertex;
//    struct AvlNode *link;
//} AvlNode;
//
//typedef struct {
//    int numVertices;
//    AvlNode **adjLists;
//    int *visited;
//} Graph;

__avl_node *createNode(int v) {
    __avl_node *newNode = malloc(sizeof(__avl_node));
    newNode->vertex = v;
    newNode->link = NULL;
    return newNode;
}

Graph *createGraph(int vertices) {
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(__avl_node *));

    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(Graph *graph, int s, int d) {
    __avl_node *newNode = createNode(d);
    newNode->link = graph->adjLists[s];
    graph->adjLists[s] = newNode;

    newNode = createNode(s);
    newNode->link = graph->adjLists[d];
    graph->adjLists[d] = newNode;
}

void dfs(Graph *graph, int vertex) {
    __avl_node *adjList = graph->adjLists[vertex];
    __avl_node *temp = adjList;

    graph->visited[vertex] = 1;
    printf("Visited %d \n", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            dfs(graph, connectedVertex);
        }
        temp = temp->link;
    }
}

int main() {
    Graph *graph = createGraph(8);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 7);
    addEdge(graph, 4, 7);
    addEdge(graph, 5, 7);
    addEdge(graph, 6, 7);

    dfs(graph, 2);

    return 0;
}


