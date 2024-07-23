//
// Created by hoseong on 2024-07-24.
//

#include <stdio.h>
#include <stdlib.h>
#include "Floyd.h"

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i == j) {
                graph->dist[i][j] = 0;
            } else {
                graph->dist[i][j] = INF;
            }
            graph->next[i][j] = -1;
        }
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    graph->dist[src][dest] = weight;
    graph->next[src][dest] = dest;
}

void floydWarshall(Graph* graph) {
    int V = graph->numVertices;

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (graph->dist[i][k] != INF && graph->dist[k][j] != INF &&
                    graph->dist[i][k] + graph->dist[k][j] < graph->dist[i][j]) {
                    graph->dist[i][j] = graph->dist[i][k] + graph->dist[k][j];
                    graph->next[i][j] = graph->next[i][k];
                }
            }
        }
    }
}

void printPath(Graph* graph, int i, int j) {
    if (graph->next[i][j] == -1) {
        printf("No path\n");
        return;
    }
    printf("%d ", i);
    while (i != j) {
        i = graph->next[i][j];
        printf("%d ", i);
    }
    printf("\n");
}

void printSolution(Graph* graph) {
    int V = graph->numVertices;

    printf("최단거리 인접행렬 결과\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph->dist[i][j] == INF) {
                printf("%7s", "INF");
            } else {
                printf("%7d", graph->dist[i][j]);
            }
        }
        printf("\n");
    }

    printf("\nPaths:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i != j && graph->dist[i][j] != INF) {
                printf("Path from %d to %d: ", i, j);
                printPath(graph, i, j);
            }
        }
    }
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

    floydWarshall(graph);
    printSolution(graph);

    free(graph);
    return 0;
}
