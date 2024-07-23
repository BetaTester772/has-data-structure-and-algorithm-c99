//
// Created by hoseong on 2024-07-23.
//

#include <stdio.h>
#include <stdlib.h>
#include "BFS.h"


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

Queue *createQueue() {
    Queue *q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Queue *q) {
    if (q->rear == -1) {
        return 1;
    } else {
        return 0;
    }
}

void enQueue(Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("\nQueue is Full!!");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

int deQueue(Queue *q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}


void bfs(Graph *graph, int startVertex) {
    Queue *q = createQueue();

    graph->visited[startVertex] = 1;
    enQueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = deQueue(q);
        printf("Visited %d\n", currentVertex);

        __avl_node *temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enQueue(q, adjVertex);
            }
            temp = temp->link;
        }
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

    bfs(graph, 2);

    return 0;
}

