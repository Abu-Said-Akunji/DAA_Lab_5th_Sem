#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Edge
{
    int src, dest, weight;
} Edge;

typedef struct Graph
{
    int V, E;
    Edge *edge;
} Graph;

Graph *createGraph(int V, int E)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (Edge *)malloc(E * sizeof(Edge));
    return graph;
}

int find(int parent[], int i)
{
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void unionSets(int parent[], int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

int compareEdges(const void *a, const void *b)
{
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

void kruskalMST(Graph *graph)
{
    int V = graph->V;
    Edge result[V];
    int e = 0;
    int i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compareEdges);

    int parent[V];
    for (int v = 0; v < V; v++)
        parent[v] = v;

    while (e < V - 1 && i < graph->E)
    {
        Edge next_edge = graph->edge[i++];
        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        if (x != y)
        {
            result[e++] = next_edge;
            unionSets(parent, x, y);
        }
    }

    printf("Edge\n");
    int totalWeight = 0;
    for (i = 0; i < e; i++)
    {
        printf("%d--%d\n", result[i].src, result[i].dest);
        totalWeight += result[i].weight;
    }

    printf("Cost\n");
    for (i = 0; i < e; i++)
    {
        printf("%d ", result[i].weight);
    }
    for (; i < V - 1; i++)
    {
        printf("+∞ ");
    }

    printf("\nTotal Weight of the Spanning Tree: %d\n", totalWeight);
}

int main()
{
    int n, m;
    FILE *infile2 = fopen("intputQ2.dat", "r");
    fscanf(infile2, "%d %d", &n, &m);
    Graph *graph = createGraph(n, m);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        fscanf(infile2, "%d %d %d", &u, &v, &w);
        graph->edge[i].src = u;
        graph->edge[i].dest = v;
        graph->edge[i].weight = w;
    }

    kruskalMST(graph);

    return 0;
}