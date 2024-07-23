//
// Created by hoseong on 2024-07-24.
//

#include <stdio.h>
#include <stdlib.h>
#include "Prim.h"

Node *createNode(int v, int weight) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int vertices) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (Node **) malloc(vertices * sizeof(Node *));
    graph->visited = (int *) malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(Graph *graph, int src, int dest, int weight) {
    Node *newNode = createNode(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

int minKey(int key[], int mstSet[], int vertices) {
    int min = INF, minIndex;
    for (int v = 0; v < vertices; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], minIndex = v;
    return minIndex;
}

void printMST(int parent[], int n, Graph *graph) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++) {
        Node *temp = graph->adjLists[i];
        while (temp) {
            if (temp->vertex == parent[i]) {
                printf("%d - %d \t%d \n", parent[i], i, temp->weight);
                break;
            }
            temp = temp->next;
        }
    }
}

void primMST(Graph *graph) {
    int vertices = graph->numVertices;
    int parent[vertices];
    int key[vertices];
    int mstSet[vertices];

    for (int i = 0; i < vertices; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices);
        mstSet[u] = 1;

        Node *temp = graph->adjLists[u];
        while (temp) {
            int v = temp->vertex;
            if (mstSet[v] == 0 && temp->weight < key[v]) {
                parent[v] = u;
                key[v] = temp->weight;
            }
            temp = temp->next;
        }
    }

    printMST(parent, vertices, graph);
}

int main() {
    int V = 5;
    Graph *graph = createGraph(V);
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 3, 4, 9);

    primMST(graph);

    free(graph);

    return 0;
}
