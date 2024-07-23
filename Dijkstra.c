//
// Created by hoseong on 2024-07-24.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Dijkstra.h"

__anode *createNode(int v, int weight) {
    __anode *newNode = (__anode *) malloc(sizeof(__anode));
    newNode->vertex = v;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int vertices) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (__anode **) malloc(vertices * sizeof(__anode *));
    graph->dist = (int *) malloc(vertices * sizeof(int));
    graph->prev = (int *) malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->dist[i] = INF;
        graph->prev[i] = -1;
    }

    return graph;
}

void addEdge(Graph *graph, int src, int dest, int weight) {
    __anode *newNode = createNode(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

int minDistance(int dist[], int sptSet[], int vertices) {
    int min = INF, minIndex;

    for (int v = 0; v < vertices; v++)
        if (sptSet[v] == 0 && dist[v] < min)
            min = dist[v], minIndex = v;

    return minIndex;
}

void printPath(Graph *graph, int j) {
    if (graph->prev[j] == -1)
        return;

    printPath(graph, graph->prev[j]);
    printf("%d ", j);
}

void printSolution(Graph *graph, int startVertex) {
    printf("Vertex\t Distance\tPath");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("\n%d -> %d \t\t %d\t\t%d ", startVertex, i, graph->dist[i], startVertex);
        printPath(graph, i);
    }
    printf("\n");
}

void dijkstra(Graph *graph, int startVertex) {
    int vertices = graph->numVertices;
    int dist[vertices];
    int sptSet[vertices];

    for (int i = 0; i < vertices; i++) {
        dist[i] = INF;
        sptSet[i] = 0;
    }

    dist[startVertex] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(dist, sptSet, vertices);
        sptSet[u] = 1;

        __anode *temp = graph->adjLists[u];
        while (temp != NULL) {
            int v = temp->vertex;

            if (!sptSet[v] && dist[u] != INF && dist[u] + temp->weight < dist[v]) {
                dist[v] = dist[u] + temp->weight;
                graph->prev[v] = u;
            }
            temp = temp->next;
        }
    }

    for (int i = 0; i < vertices; i++)
        graph->dist[i] = dist[i];

    printSolution(graph, startVertex);
}

int main() {
    int V = 5;
    Graph *graph = createGraph(V);
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 5);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 2, 3, 4);
    addEdge(graph, 3, 2, 6);
    addEdge(graph, 3, 0, 7);
    addEdge(graph, 4, 1, 3);
    addEdge(graph, 4, 2, 9);
    addEdge(graph, 4, 3, 2);

    dijkstra(graph, 0);

    return 0;
}
