#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int vertices[MAX_VERTICES];
    int edges[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
    int num_edges;
} Graph;

Graph* create_graph(int num_vertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    for (int i = 0; i < num_vertices; i++) {   
        graph->vertices[i] = i;
        for (int j = 0; j < num_vertices; j++) {
            graph->edges[i][j] = 0;
        }
    }
    return graph;
}

void add_edge(Graph* graph, int u, int v) {
    graph->edges[u][v] = 1;
    graph->edges[v][u] = 1;
    graph->num_edges++;
}

void remove_edge(Graph* graph, int u, int v) {
    graph->edges[u][v] = 0;
    graph->edges[v][u] = 0;
    graph->num_edges--;
}

bool has_edge(Graph* graph, int u, int v) {
    return graph->edges[u][v] == 1;
}

void print_graph(Graph* graph) {
    printf("Vertices: ");
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("%d ", graph->vertices[i]);
    }
    printf("\n");
    printf("Edges: \n");
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = i+1; j < graph->num_vertices; j++) {
            if (has_edge(graph, i, j)) {
                printf("(%d, %d) ", i, j);
            }
        }
    }
    printf("\n");
}

int main() {
    Graph* graph = create_graph(5);
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 0);

    printf("Graph:\n");
    print_graph(graph);

    remove_edge(graph, 2, 3);

    printf("Graph after removing (2, 3):\n");
    print_graph(graph);

    return 0;
}
